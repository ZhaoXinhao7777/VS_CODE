class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        // n表示进程数量，logs表示日志
        vector<int> res(n, 0);
        stack<pair<int, int>> s; // 辅助栈，<first,second>分别表示id和运行时间
        for (auto &it : logs)
        {
            string operation = "";
            int funcId = 0, time = 0, index = 0, logSize = it.size();

            // 第一步：取函数id
            while (it[index] != ':')
            {
                funcId = funcId * 10 + it[index++] - '0';
            }

            index++;
            // 取操作类型
            while (it[index] != ':')
            {
                operation += it[index++];
            }

            index++;
            // 取时间戳
            while (index < logSize)
                time = time * 10 + it[index++] - '0';
            //  判断操作类型，如果为start，则入栈
            if (operation == "start")
                // 注意是键值对
                s.push({funcId, time});
            else
            {
                // 操作类型则为end
                int runTime = time - s.top().second + 1; // 计算栈顶id运行时间
                s.pop();
                res[funcId] += runTime; // 加入总时间中
                if (!s.empty())         // 如果此时栈不为空，则说明当前栈顶函数里还嵌套了当前函数id，需要减去当前函数的运行时间
                    res[s.top().first] -= runTime;
            }
        }
        return res;
    }
};