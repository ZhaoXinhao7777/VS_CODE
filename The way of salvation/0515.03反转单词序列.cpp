class Solution
{
public:
    // 利用栈的后进先出特性
    string ReverseSentence(string str)
    {
        int n = str.length();
        stack<string> s;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && str[j] != ' ')
                j++;
            s.push(str.substr(i, j - i));
            i = j;
        }
        str = "";
        while (!s.empty())
        {
            str += s.top();
            s.pop();
            if (!s.empty())
                str += " ";
        }
        return str;
    }
    // //利用reserve函数进行逆序
    // string ReverseSentence(string str) {
    //    int n=str.length();
    //    reverse(str.begin(),str.end());
    //    for(int i=0;i<n;i++)
    //    {
    //         int j=i;
    //         //找空格位置
    //         while(j<n&&str[j]!=' ')
    //         {
    //             j++;
    //         }
    //         reverse(str.begin()+i,str.begin()+j);
    //         i=j;
    //    }
    //         return str;
    // }
};