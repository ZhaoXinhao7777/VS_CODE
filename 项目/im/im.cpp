#include <iostream>
#include "util.hpp"
#include "db.hpp"

#define HSOT "127.0.0.1"
#define USER "root"
#define PASS ""
#define DB "im_system"
#define PORT 3306

void user_table_test()
{
    im::UserTable *ut = new im::UserTable(HSOT, USER, PASS, DB, PORT);
    Json::Value user;
    user["username"] = "ZhouJielun";
    user["nickname"] = "周杰伦";
    user["password"] = "123456";
    // ut->insert(user);
    ut->remove(4);
}
int main()
{
    user_table_test();

    return 0;
}