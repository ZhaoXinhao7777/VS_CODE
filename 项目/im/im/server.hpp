#ifndef _M_SERVER_H_
#define _M_SERVER_H_

#include <iostream>
#include "mongoose.h"
#include <string>
#include "db.hpp"
#include "util.hpp"
#include "session.hpp"

// 对收到的数据进行转发
namespace im
{
#define HSOT "127.0.0.1"
#define USER "root"
#define PASS ""
#define DB "im_system"
#define PORT 3306
    class Server
    {
    private:
        struct mg_mgr _mgr;
        std::string _rootdir = "./wwwroot";
        UserTable *user_table;
        MsgTable *msg_table;
        SessionManager *ss_manager;
        // std::unordered_map<struct mg_connection *, uint64_t> conn_ss;

    private:
        static bool get_history_msg(struct mg_connection *c,
                                    struct mg_http_message *hm,
                                    Server *srv)
        {
            struct mg_str *cookie = mg_http_get_header(hm, "Cookie");
            if (cookie == NULL)
            {
                std::cout << "没有获取到cookie\n";
                mg_http_reply(c, 401, "", "%s", "401  Unauthorized");
                return false;
            }
            std::string cookie_str(cookie->ptr, cookie->len);
            size_t pos = cookie_str.find("=");
            std::string ssid_str = cookie_str.substr(pos + 1);
            uint64_t ssid = std::stol(ssid_str);

            SessionManager *ssm = srv->get_ss_manager();
            if (ssm->exists(ssid) == false)
            {
                std::cout << "没有对应的session\n";
                mg_http_reply(c, 401, "", "%s", "401 Unauthorized");
                return false;
            }
            MsgTable *table = srv->get_msg_table();
            Json::Value msgs;
            bool ret = table->select_part(44000, &msgs);
            if (ret == false)
            {
                Json::Value resp_json;
                resp_json["result"] = false;
                resp_json["reason"] = "获取历史聊天消息失败";
                std::string body;
                JsonUtil::serialize(resp_json, &body);
                mg_http_reply(c, 500, NULL, "%s", body.c_str());
                return false;
            }
            std::string body;
            JsonUtil::serialize(msgs, &body);
            Json::Value user;
            ssm->get_session_user(ssid, &user);
            // 移除旧session,设置新session确保每次获取的session都是最新的
            ssm->remove(ssid);
            ssid = ssm->insert(user);
            std::string header = "Content-Type:application/json\r\n";
            header += "Set-Cookie:SSID=" + std::to_string(ssid) + "\r\n";

            mg_http_reply(c, 200, header.c_str(), "%s", body.c_str());
        }
        static bool user_add(struct mg_connection *c,
                             struct mg_http_message *hm,
                             Server *srv)
        {
            // 1.请求正文的解析，得到用户信息
            std::string req_body(hm->body.ptr, hm->body.len);
            Json::Value user_json;
            Json::Value resp_json;
            bool ret = JsonUtil::unserialize(req_body, &user_json);

            if (ret == false)
            {
                resp_json["result"] = false;
                resp_json["reason"] = "用户解析失败";
                std::string body;
                JsonUtil::serialize(resp_json, &body);
                mg_http_reply(c, 400, NULL, "%s", body.c_str());
                return false;
            }

            // 将用户数据插入数据库
            UserTable *table = srv->get_user_table();
            ret = table->insert(user_json);

            if (ret == false)
            {
                resp_json["result"] = false;
                resp_json["reason"] = "向数据库 插入数据失败";
                std::string body;
                JsonUtil::serialize(resp_json, &body);
                mg_http_reply(c, 500, NULL, "%s", body.c_str());
                return false;
            }

            resp_json["result"] = true;
            resp_json["reason"] = "新增用户成功";
            std::string body;
            JsonUtil::serialize(resp_json, &body);
            // 对客户端进行响应成功

            mg_http_reply(c, 200, NULL, "%s", body.c_str());

            return true;
        }
        static bool user_login(struct mg_connection *c,
                               struct mg_http_message *hm,
                               Server *srv)
        {
            // 1.从请求正文中提交用户名，密码信息
            std::string req_body(hm->body.ptr, hm->body.len);

            // 2.进行json反序列化
            Json::Value user_json;
            Json::Value resp_json;
            bool ret = JsonUtil::unserialize(req_body, &user_json);
            if (ret == false)
            {
                resp_json["result"] = "false";
                resp_json["reson"] = "用户信息验证失败";
                std::string body;
                JsonUtil::serialize(resp_json, &body);
                mg_http_reply(c, 400, NULL, "%s", body.c_str());
                return false;
            }

            // 3.在数据库中进行验证
            UserTable *table = srv->get_user_table();
            ret = table->check_login(user_json);
            if (ret == false)
            {
                resp_json["result"] = "false";
                resp_json["reson"] = "用户名密码错误";
                std::string body;
                JsonUtil::serialize(resp_json, &body);
                mg_http_reply(c, 401, NULL, "%s", body.c_str());
                return false;
            }
            // 4.为客户端新建会话
            SessionManager *ssm = srv->get_ss_manager();

            uint64_t ssid = ssm->insert(user_json);
            // std::unordered_map<struct mg_connection *, uint64_t> *conn_ss = srv->get_conn_ss();
            //  建立映射关系
            //  conn_ss.insert(std::make_pair<c, ssid>);
            // (*conn_ss)[c] = ssid;
            // 设置cookie
            std::string cookie = "Set-Cookie:SSID=" + std::to_string(ssid) + "\r\n";
            // 5.返回200
            resp_json["result"] = true;
            resp_json["reson"] = "登录成功";
            std::string body;
            JsonUtil::serialize(resp_json, &body);
            mg_http_reply(c, 200, cookie.c_str(), "%s", body.c_str());

            return true;
        }

    private:
        // 广播
        static void broadcast_msg(struct mg_mgr *mgr, const std::string &msg)
        {
            struct mg_connection *conn = mgr->conns;
            for (; conn != NULL; conn = conn->next)
            {

                if (conn->is_websocket)
                {
                    mg_ws_send(conn, msg.c_str(), msg.size(), WEBSOCKET_OP_TEXT);
                }
            }
        }
        // 回调函数内部进行业务处理
        static void handler(struct mg_connection *c,
                            int ev,
                            void *ev_data,
                            void *fn_data)
        {
            Server *srv = (Server *)fn_data;
            if (ev == MG_EV_HTTP_MSG)
            {
                struct mg_http_message *hm = (struct mg_http_message *)ev_data;
                // 请求方法
                std::string method(hm->method.ptr, hm->method.len);
                // 请求路径
                std::string uri(hm->uri.ptr, hm->uri.len);
                // 处理资源动态请求
                std::cout << method << "\t" << uri << std::endl;

                // 新增用户
                if (method == "POST" && uri == "/user")
                {
                    user_add(c, hm, srv);
                }
                // 登录验证
                else if (method == "POST" && uri == "/login")
                {

                    user_login(c, hm, srv);
                }
                // 修改密码
                else if (method == "PUT" && uri == "/user/passwd")
                {
                }
                // 修改昵称
                else if (method == "PUT" && uri == "/user/nickname")
                {
                }
                // 删除用户
                else if (method == "DELETE" && uri == "/user")
                {
                }
                // 获取用户信息
                else if (method == "GET" && uri == "/user")
                {
                    struct mg_str *cookie = mg_http_get_header(hm, "Cookie");
                    if (cookie == NULL)
                    {
                        std::cout << "没有获取到cookie\n";
                        mg_http_reply(c, 401, "", "%s", "401  Unauthorized");
                        return;
                    }

                    std::string cookie_str(cookie->ptr, cookie->len);
                    // std::cout << cookie_str << std::endl;

                    size_t pos = cookie_str.find("=");

                    // std::cout << pos << std::endl;
                    std::string ssid_str = cookie_str.substr(pos + 1);
                    // std::cout << ssid_str << std::endl;

                    uint64_t ssid = std::stol(ssid_str);
                    SessionManager *ssm = srv->get_ss_manager();
                    if (ssm->exists(ssid) == false)
                    {
                        std::cout << "没有对应的session\n";
                        mg_http_reply(c, 401, "", "%s", "401 Unauthorized");
                        return;
                    }
                    Json::Value user;
                    ssm->get_session_user(ssid, &user);

                    UserTable *table = srv->get_user_table();
                    Json::Value new_user;
                    table->seletc_by_name(user["username"].asString(), &new_user);
                    std::string user_str;
                    JsonUtil::serialize(new_user, &user_str);

                    // 移除旧session,设置新session确保每次获取的session都是最新的
                    ssm->remove(ssid);
                    ssid = ssm->insert(new_user);
                    std::string header = "Content-Type:application/json\r\n";
                    header += "Set-Cookie:SSID=" + std::to_string(ssid) + "\r\n";

                    mg_http_reply(c, 200, header.c_str(), "%s", user_str.c_str());
                }
                // 获取历史聊天消息
                else if (method == "GET" && uri == "/message")
                {
                    get_history_msg(c, hm, srv);
                }
                // 协议切换请求 切换到websocket请求
                else if (method == "GET" && uri == "/ws")
                {
                    struct mg_str *cookie = mg_http_get_header(hm, "Cookie");
                    if (cookie == NULL)
                    {
                        mg_http_reply(c, 401, "", "%s", "401  Unauthorized");
                        return;
                    }
                    std::string cookie_str(cookie->ptr, cookie->len);
                    // std::cout << "------[" << cookie_str << "]" << std::endl;
                    //  struct mg_str ssid_str = mg_str("");
                    //  ssid_str = mg_http_get_header_var(*cookie, mg_str("SSID"));
                    //  std::string ssid(ssid_str.ptr, ssid_str.len);
                    //  std::cout << ssid << std::endl;
                    size_t pos = cookie_str.find("=");
                    std::string ssid_str = cookie_str.substr(pos + 1);
                    uint64_t ssid = std::stol(ssid_str);
                    SessionManager *ssm = srv->get_ss_manager();
                    if (ssm->exists(ssid) == false)
                    {
                        mg_http_reply(c, 401, "", "%s", "401 Unauthorized");
                        return;
                    }
                    mg_ws_upgrade(c, hm, NULL);
                    ssm->remove(ssid);
                }
                // 除了/hello请求以外的请求，其他请求都认为是静态资源请求
                else
                {
                    // 通过opts设置静态资源根目录
                    struct mg_http_serve_opts opts = {.root_dir = srv->rootdir().c_str()};

                    // 让连接的处理，到静态资源根目录下找对应文件，进行响应
                    // 找不到，最终返回404
                    mg_http_serve_dir(c, hm, &opts);
                }
            }

            // websocket握手成功
            else if (ev == MG_EV_WS_OPEN)
            {
                // 在客户端实现，不在服务器端实现了

                // // 握手成功，广播xxx上线st
                // std::unordered_map<struct mg_connection *, uint64_t> *conn_ss = srv->get_conn_ss();
                // auto it = conn_ss->find(c);
                // if (it == conn_ss->end())
                // {
                //     return;
                // }
                // uint64_t ssid = it->second;

                // SessionManager *ssm = srv->get_ss_manager();
                // bool ret = ssm->exists(it->second);
                // if (ret != false)
                // {
                //     Json::Value user;
                //     ssm->get_session_user(ssid, &user);
                //     std::string msg = user["nickname"].asString() + " 加入聊天室 ";
                //     broadcast_msg(srv->get_mgr(), msg);
                // }
            }
            // websocket数据通信--客户端发送了一条聊天消息
            else if (ev == MG_EV_WS_MSG)
            {
                // 客户端发送一条聊天新消息，广播这条消息
                // 获取连接对应的session
                struct mg_ws_message *wsmsg = (struct mg_ws_message *)ev_data;
                std::string msg(wsmsg->data.ptr, wsmsg->data.len);
                // std::cout << msg << std::endl;
                broadcast_msg(srv->get_mgr(), msg);

                Json::Value msg_json;
                JsonUtil::unserialize(msg, &msg_json);
                // 获取历史消息，并将其插入数据库中
                srv->get_msg_table()->insert(msg_json);
            }
            // 通信连接断开
            else if (ev == MG_EV_CLOSE)
            {
                // 在客户端实现，不在服务器端实现了

                // // 获取连接对应的session
                // std::unordered_map<struct mg_connection *, uint64_t> *conn_ss = srv->get_conn_ss();
                // auto it = conn_ss->find(c);
                // if (it == conn_ss->end())
                // {
                //     return;
                // }
                // uint64_t ssid = it->second;
                // // 移除session
                // SessionManager *ssm = srv->get_ss_manager();
                // bool ret = ssm->exists(it->second);
                // if (ret != false)
                // {
                //     Json::Value user;
                //     ssm->get_session_user(ssid, &user);
                //     std::string msg = user["nickname"].asString() + " 下线了 ";
                //     broadcast_msg(srv->get_mgr(), msg);
                // }
                // // 将连接与session的关系信息，从关系信息表中删除
                // conn_ss->erase(c);
            }
        }

    public:
        Server(const std::string &host,
               const std::string &user,
               const std::string &pass,
               const std::string &db,
               int port)
        {
            user_table = new UserTable(host, user, pass, db, port);
            msg_table = new MsgTable(host, user, pass, db, port);
            ss_manager = new SessionManager();
            mg_mgr_init(&_mgr);
        }
        struct mg_mgr *get_mgr()
        {
            return &_mgr;
        }
        const std::string &rootdir()
        {
            return _rootdir;
        }
        void Start(int port)
        {
            std::string address = "0.0.0.0:" + std::to_string(port);
            mg_http_listen(&_mgr, address.c_str(), handler, this);

            for (;;)
            {
                mg_mgr_poll(&_mgr, 1000);
            }
        }
        UserTable *get_user_table()
        {
            return user_table;
        }
        MsgTable *get_msg_table()
        {
            return msg_table;
        }
        SessionManager *get_ss_manager()
        {
            return ss_manager;
        }
        // std::unordered_map<struct mg_connection *, uint64_t> *get_conn_ss()
        //{
        //     return &conn_ss;
        // }
    };
}

#endif