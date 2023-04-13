#ifndef __M_UTIL_H__
#define __M_UTIL_H__

#endif

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <jsoncpp/json/json.h>
#include <mysql/mysql.h>
namespace im
{
    // json工具类：jison序列化，json反序列化
    class JsonUtil
    {
    public:
        static void serialize(Json::Value &value, std::string &body)
        {
            Json::StreamWriterBuilder swb;

            std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
            std::stringstream ss;
            int ret = sw->write(value, &ss);
            if (ret != 0)
            {
                std::cout << "serialize failed!\n";
                return;
            }
            body = ss.str();
            return;
        }

        // 反序列化
        static bool unserialize(std::string &body, Json::Value &value)
        {
            Json::CharReaderBuilder crb;
            std::unique_ptr<Json::CharReader> cr(crb.newCharReader());

            std::string err;
            bool ret = cr->parse(body.c_str(), body.c_str() + body.size(), &value, &err);

            if (ret == false)
            {
                std::cout << "unserialize failed!" << std::endl;
                return false;
            }
            return true;
        }
    };

    // 数据库访问操作的封装
    class MysqlUtil
    {
    public:
        // 创建初始化,连接服务器，设置字符集，选择数据库
        static MYSQL *mysql_create(const std::string &host,
                                   const std::string &user,
                                   const std::string &pass,
                                   const std::string &db,
                                   int port)
        {
            MYSQL *mysql = mysql_init(NULL);
            if (mysql == NULL)
            {
                std::cout << "mysql init failed!\n";
                return NULL;
            }
            if (mysql_real_connect(mysql, host.c_str(),
                                   user.c_str(), pass.c_str(), db.c_str(), port, NULL, 0) == NULL)
            {
                std::cout << "connect server failed: " << mysql_errno(mysql) << std::endl;
                return NULL;
            }
            // 设置字符集
            mysql_set_character_set(mysql, "utf8");
            return mysql;
        }

        static bool mysql_exec(MYSQL *mysql, const std::string &sql)
        {
            int ret = mysql_query(mysql, sql.c_str());
            if (ret != 0)
            {
                std::cout << sql << std::endl;
                std::cout << "query faild!"
                          << " " << mysql_error(mysql) << std::endl;
                return false;
            }
            return true;
        }

        static void mysql_destory(MYSQL *mysql)
        {
            if (mysql == NULL)
            {
                return;
            }
            mysql_close(mysql);
        }
    };

}