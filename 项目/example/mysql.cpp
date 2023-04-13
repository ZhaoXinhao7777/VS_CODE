#include <iostream>
#include<cstdio>
#include <mysql/mysql.h>

int main()
{
    // 初始化句柄
    MYSQL *mysql = mysql_init(NULL);
    if (mysql == NULL)
    {
        std::cout << "mysql init failed!\n";
        return -1;
    }
    // 连接服务器
    // mysql_real_connect(mysql,host,user,passwd,dbname,port,socket,flag)
    if (mysql_real_connect(mysql, "127.0.0.1", "root", "", "db888", 0, NULL, 0) == NULL)
    {
        std::cout << "connect server failed: " << mysql_errno(mysql) << std::endl;
        return -1;
    }
    // 设置字符集
    mysql_set_character_set(mysql, "utf8");
    // 选择数据库
    // mysql_select_db(mysql,"db888");

    // 执行语句
    // 插入：//const char *sql = "insert into tbstu values(null,'孙八',19,65,73,now());";
    // 修改：//const char* sql="update tbstu set age=100 where sn =2";
    // 删除：//const char *sql = "delete from tbstu where name='李四'";
    // 查询：
    const char *sql = "select * from tbstu;";

    int ret = mysql_query(mysql, sql);
    
    if (ret != 0)
    {
        std::cout << sql << std::endl;
        std::cout << "query faild!"
                  << " " << mysql_error(mysql) << std::endl;
        return -1;
    }

    // 保存结果集到本地
    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == NULL)
    {
        std::cout << "store result failed!"
                  << " " << mysql_error(mysql) << std::endl;
        return -1;
    }
    // 获取结果集条数，列数，
    int num_row = mysql_num_rows(res);
    int num_col = mysql_num_fields(res);
    // 根据条数和列数，遍历结果集
    for (int i = 0; i < num_row; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(res);
        for (int j = 0; j < num_col; j++)
        {
            printf("%s\t", row[j]);
        }
        printf("\n");
    }
    // 释放结果集
    mysql_free_result(res);

    mysql_close(mysql);

    return 0;
}