#include "util.hpp"
#include "db.hpp"
#include "server.hpp"

#define HSOT "127.0.0.1"
#define USER "root"
#define PASS ""
#define DB "im_system"
#define PORT 3306

void user_table_test()
{
    im::UserTable *ut = new im::UserTable(HSOT, USER, PASS, DB, PORT);
    Json::Value user;
    user["username"] = "Xiaoxiaozhao";
    user["nickname"] = "小小赵";
    user["password"] = "111111";
    user["old_password"] = "123123";
    user["new_password"] = "111111";

    // ut->insert(user);
    // ut->remove(6);
    // ut->remove(7);
    // ut->remove(26);

    // ut->update_password(user);
    // ut->update_nickname(user);

    Json::Value root;
    // ut->select_by_id(2, &root);
    ut->seletc_by_name("Xiaoxiaozhao", &root);
    std::string body;
    im::JsonUtil::serialize(root, &body);
    std::cout << body << std::endl;
}
void msg_test()
{
    im::MsgTable *mt = new im::MsgTable(HSOT, USER, PASS, DB, PORT);
    Json::Value msg;
    msg["uid"] = 3;
    msg["msg"] = "hello";
    mt->insert(msg);

    Json::Value root;
    mt->select_part(200, &root);
    std::string body;
    im::JsonUtil::serialize(root, &body);
    std::cout << body << std::endl;
}
void server_test(int port)
{
    im::Server server(HSOT, USER, PASS, DB, PORT);
    server.Start(port);
}
int main()
{
    // user_table_test();
    //  msg_test();
    server_test(9000);
    return 0;
}