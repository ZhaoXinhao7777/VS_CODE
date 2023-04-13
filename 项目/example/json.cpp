#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <jsoncpp/json/json.h>
// 序列化
void serialize(Json::Value &value, std::string &body)
{
    Json::StreamWriterBuilder swb;
    // 输出风格
    swb["commentStyle"] = "None";

    // Json::StreamWriter *sw = swb.newStreamWriter();
    // 智能指针
    std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
    std::stringstream ss;
    int ret = sw->write(value, &ss);
    if (ret != 0)
    {
        std::cout << "serialize failed!\n";
        // delete sw;
        return;
    }
    body = ss.str();
    // delete sw;
    return;
}

// 反序列化
bool unserialize(std::string &body, Json::Value &value)
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

int main()
{
    Json::Value val;
    val["姓名"] = "小明";
    val["年龄"] = 18;
    val["成绩"].append(45);
    val["成绩"].append(79);
    val["成绩"].append(67);

    std::string body;
    serialize(val, body);

    std::cout << body << std::endl;

    Json::Value stu;
    unserialize(body, stu);
    std::cout << stu["姓名"].asString() << std::endl;
    std::cout << stu["年龄"].asInt() << std::endl;
    if (stu["成绩"].isArray())
    {
        for (int i = 0; i < stu["成绩"].size(); i++)
        {
            std::cout << stu["成绩"][i].asFloat() << std::endl;
        }
    }

    return 0;
}