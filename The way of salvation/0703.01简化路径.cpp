class Solution
{
public:
    // 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

    // 一个点（.）表示当前目录本身
    // 两个点 （..） 表示将目录切换到上一级（指向父目录）
    string simplifyPath(string path)
    {
        string res;
        vector<string> v;
        for (int i = 0; i < path.size(); ++i)
        {
            string temp = "";
            while (path[i] != '/' && i < path.size()) // 遇到'/'则跳出循环判断，temo到底是什么
                temp += path[i++];
            // 表示当前目录
            if (temp == ".")
                continue;
            // 表示当前目录的上一个目录
            else if (temp == "..")
            {
                // 判断v是否为空
                if (!v.empty())
                {
                    v.pop_back();
                }
                else
                {
                    continue;
                }
            } // 正常字符串
            else if (temp.size() != 0)
                v.push_back(temp);
        }
        for (int i = 0; i < v.size(); i++)
        {
            res += "/";
            res.append(v[i]); // 尾增
        }
        return res.size() == 0 ? "/" : res;
    }
};