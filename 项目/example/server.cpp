#include <iostream>
#include <string>
#include "mongoose.h"
#include <cstring>

#define WWWROOT "./wwwroot"
void handler(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    // ev 保存了当前c链接触发的事件
    //  MG_EV_CLOSE 连接断开事件
    //  MG_EV_HTTP_MSG收到一个HTTP请求事件
    //  MG_EV_WS_OPEN websocket握手成功
    //  MG_EV_MSG 收到一条websocket消息

    if (ev == MG_EV_HTTP_MSG)
    {
        struct mg_http_message *hm = (struct mg_http_message *)ev_data;
        // 处理资源动态请求
        if (mg_http_match_uri(hm, "/hello"))
        {
            std::string body;
            body = "<html><body><h1>Hello World</h1></body></html>";

            mg_http_reply(c, 200, "", "%s", body.c_str());
            // std::string method(hm->method.ptr, hm->method.len);
            // std::string path(hm->uri.ptr, hm->uri.len);
            // if (methode == "GET" && path == "/hello")
            // {
            //  }
        }
        // 静态资源请求
        else // 除了/hello请求以外的请求，其他请求都认为是静态资源请求
        {
            // 通过opts设置静态资源根目录
            struct mg_http_serve_opts opts = {.root_dir = WWWROOT};

            // 让连接的处理，到静态资源根目录下找对应文件，进行响应
            // 找不到，最终返回404
            mg_http_serve_dir(c, hm, &opts);
        }
    }
}
int main()
{
    struct mg_mgr mgr;
    // 句柄初始化
    // void mg_mgr_init(struct mg_mgr *mgr);

    mg_mgr_init(&mgr);
    // 绑定地址，进行回调
    // struct mg_connection *mg_http_listen(
    //      struct mg_mgr *mgr,
    //      const char *url,//服务器地址
    //      mg_event_handler_t fn,//回调函数
    //      void *fn_data)//给回调设置的参数
    //
    mg_http_listen(&mgr, "0.0.0.0:9000", handler, &mgr);

    // 开始循环监听所有描述的事件（是否可读）
    // 一旦哪个描述符有可读事件了，就会接受数据，解析数据
    // 然后调用handler回调函数进行业务处理
    for (;;)
    {
        mg_mgr_poll(&mgr, 1000);
    }
    return 0;
}