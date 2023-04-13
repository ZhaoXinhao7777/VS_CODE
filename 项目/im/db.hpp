#ifndef __M_DB_H__
#define __M_DB_H__

#endif

// #include "util.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <jsoncpp/json/json.h>
#include <mutex>
#include <cassert>
#include <mysql/mysql.h>

namespace im
{
    class UserTable
    {
    private:
        MYSQL *_mysql;
        std::mutex _mutex;

    public:
        // 初始化数据库操作句柄
        UserTable(const std::string &host,
                  const std::string &user,
                  const std::string &pass,
                  const std::string &db,
                  int port)
        {
            _mysql = MysqlUtil::mysql_create(host, user, pass, db, port);
            assert(_mysql != NULL);
        }
        // 释放数据库操作句柄
        ~UserTable()
        {
            MysqlUtil::mysql_destory(_mysql);
        }
        // 新增用户
        bool insert(const Json::Value &user)
        {
            // ID username nickname passwd creat_time
#define INSERT_USER "insert user values(null,'%s','%s',MD5('%s'),now());"
            char sql[4096] = {0};
            snprintf(sql, 4095, INSERT_USER,
                     user["username"].asCString(), // 获取C语言的字符串
                     user["nickname"].asCString(),
                     user["password"].asCString());
            // printf(INSERT_USER, user["username"].asCString(),
            //        user["nickname"].asCString(),
            //        user["password"].asCString());
            return MysqlUtil::mysql_exec(_mysql, sql);
        }
        // 登录验证
        bool check_login(const Json::Value &user)
        {
            // 在数据库中，有无一个用户信息，用户名和密码和当前用户信息一致
#define LOGIN_CHECK "select id form user where username='%s' and password=MD5('%s');"
            char sql[4096] = {0};
            snprintf(sql, 4095, LOGIN_CHECK,
                     user["username"].asCString(),
                     user["password"].asCString());
            return MysqlUtil::mysql_exec(_mysql, sql);
        }
        // 修改密码
        bool update_password(const Json::Value &user)
        {
#define MOD_PASSWD_BY_NAME "updata user set password=MD5('%s') where username='%s' and password=MD5('%s');"
            char sql[4096] = {0};
            snprintf(sql, 4095, MOD_PASSWD_BY_NAME,
                     user["new_password"].asCString(),
                     user["username"].asCString(),
                     user["old_password"].asCString());
            return MysqlUtil::mysql_exec(_mysql, sql);
        }
        // 昵称修改
        bool update_nickname(const Json::Value &user)
        {
#define MOD_NICKNAME_BY_NAME "updata user set nickname='%s' where username='%s' and password=MD5('%s');"
            char sql[4096] = {0};
            snprintf(sql, 4095, MOD_NICKNAME_BY_NAME,
                     user["nickname"].asCString(),
                     user["username"].asCString(),
                     user["password"].asCString());
            return MysqlUtil::mysql_exec(_mysql, sql);
        }
        // 删除 用户
        bool remove(int id)
        {
#define DELETE_UESR "delete from user where id=%d;"
            char sql[4096] = {0};
            snprintf(sql, 4095, DELETE_UESR, id);
            return MysqlUtil::mysql_exec(_mysql, sql);
        }
        // 获取用户信息
        bool select_by_id(int id, Json::Value *user)
        {
#define SELECT_USER_BY_ID "select username,nickname from user where id=%d;"
            char sql[4096] = {0};
            snprintf(sql, 4095, SELECT_USER_BY_ID, id);
            MYSQL_RES *res;
            {
                // 使用lock对象管理互斥锁，实例化的同时会加锁
                // lock对象被释放时，会自动解锁
                std::unique_lock<std::mutex> lock(_mutex);
                bool ret = MysqlUtil::mysql_exec(_mysql, sql);
                if (ret == false)
                    return false;
                res = mysql_store_result(_mysql);
                if (res == NULL)
                {
                    std::cout << "store result faild:" << mysql_error(_mysql) << std::endl;
                    return false;
                }
            }
            int num_row = mysql_num_rows(res);
            if (num_row != 1)
            {
                std::cout << "qurey result error!" << std::endl;
                return false;
            }
            MYSQL_ROW row = mysql_fetch_row(res);
            (*user)["id"] = id;
            (*user)["username"] = row[0];
            (*user)["nickname"] = row[1];
            mysql_free_result(res);
            return true;
        }
        bool seletc_by_name(const std::string name, Json::Value *user)
        {
#define SELECT_USER_BY_NAME "select id,nickname from user where username='%s';"
            char sql[4096] = {0};
            snprintf(sql, 4095, SELECT_USER_BY_NAME, name.c_str());
            MYSQL_RES *res;
            {
                // 使用lock对象管理互斥锁，实例化的同时会加锁
                // lock对象被释放时，会自动解锁
                std::unique_lock<std::mutex> lock(_mutex);
                bool ret = MysqlUtil::mysql_exec(_mysql, sql);
                if (ret == false)
                    return false;
                res = mysql_store_result(_mysql);
                if (res == NULL)
                {
                    std::cout << "store result faild:" << mysql_error(_mysql) << std::endl;
                    return false;
                }
            }
            int num_row = mysql_num_rows(res);
            if (num_row != 1)
            {
                std::cout << "qurey result error!" << std::endl;
                return false;
            }
            MYSQL_ROW row = mysql_fetch_row(res);
            (*user)["id"] = std::stoi(row[0]);
            (*user)["username"] = name;
            (*user)["nickname"] = row[1];
            mysql_free_result(res);
            return true;
        }
    };

    // 消息类
    class MsgTable
    {
    private:
        MYSQL *_mysql;
        std::mutex _mutex;

    public:
        MsgTable(const std::string &host,
                 const std::string &user,
                 const std::string &pass,
                 const std::string &db,
                 int port)
        {
            _mysql = MysqlUtil::mysql_create(host, user, pass, db, port);
            assert(_mysql != NULL);
        }
        ~MsgTable()
        {
            MysqlUtil::mysql_destory(_mysql);
        }
        // 消息插入
        bool insert(const Json::Value &msg)
        {
            // id uid msg ctime
#define INSERT_MSG "insert `message` values(null,%d,'%s',now());"
            char sql[4096] = {0};
            snprintf(sql, 4095, INSERT_MSG,
                     msg["uid"].asInt(),
                     msg["msg"].asCString());
            return MysqlUtil::mysql_exec(_mysql, sql);
        }
        // 消息获取
        bool select_part(int sec, Json::Value *msg)
        {
#define SELECT_PART_MSG "select id,`uid`,msg,ctime from message where timestampdiff(second,ctime,now())>%d;"
            char sql[4096] = {0};
            snprintf(sql, 4095, SELECT_PART_MSG, sec);
            MYSQL_RES *res;
            {
                std::unique_lock<std::mutex> lock(_mutex);
                bool ret = MysqlUtil::mysql_exec(_mysql, sql);
                if (ret == false)
                    return false;
                res = mysql_store_result(_mysql);
                if (res == NULL)
                {
                    std::cout << "store result faild:" << mysql_error(_mysql) << std::endl;
                    return false;
                }
                return true;
            }
            int num_row = mysql_num_rows(res);
            for (int i = 0; i < num_row; i++)
            {
                MYSQL_ROW row = mysql_fetch_row(res);
                Json::Value m;
                m["id"] = std::stoi(row[0]);
                m["uid"] = std::stoi(row[1]);
                m["msg"] = row[2];
                m["ctime"] = row[3];
                msg->append(m);
            }
            mysql_free_result(res);
            return true;
        }
    };
}