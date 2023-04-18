#ifndef __M_SESSION_H__
#define __M_SESSION_H__
#include <mutex>
#include <unordered_map>
#include <jsoncpp/json/json.h>
#include <typeinfo>

namespace im
{
    struct Session
    {
        uint64_t ssid;
        Json::Value user;
        struct mg_connection *conn;
    };
    class SessionManager
    {
    private:
        uint64_t _next_id;
        std::mutex _mutex;
        std::unordered_map<uint64_t, Json::Value> _ss;

    public:
        SessionManager() : _next_id(1)
        {
        }
        // 为登录成功的用户新增会话
        uint64_t insert(const Json::Value &user)
        {
            std::unique_lock<std::mutex> lock(_mutex);
            int ssid = _next_id;
            _ss.insert(std::make_pair(_next_id, user));
            _next_id++;
            return ssid;
        }
        // 获取用户信息
        bool get_session_user(uint64_t ssid, Json::Value *user)
        {
            // unordered_map::find(value)在hash表中查找指定元素，返回一个迭代器
            auto it = _ss.find(ssid);
            // unordered_map::end()末尾不存在元素
            if (it == _ss.end())
            {
                return false;
            }
            // it->first是ssid，it->second是Json::Value用户信息
            *user = it->second;
            return true;
        }
        // 移除用户信息
        void remove(uint64_t ssid)
        {
            _ss.erase(ssid);
        }
        // 判断用户是否存在
        bool exists(uint64_t ssid)
        {
            auto it = _ss.find(ssid);
            if (it == _ss.end())
            {
                return false;
            }
            return true;
        }
    };
}

#endif