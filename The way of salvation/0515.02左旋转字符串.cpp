#include <algorithm>
#include <cstring>
#include <iterator>
class Solution
{
public:
    // 借助reverse函数三次反转
    string LeftRotateString(string str, int n)
    {
        int m = str.size();
        if (m == 0)
            return "";
        n = n % m;
        reverse(str.begin(), str.end());

        reverse(str.begin(), str.end() - n);

        reverse(str.end() - n, str.end());

        return str;
    }
    // //借助库函数 substr(pos,n);
    // // 返回pos开始的n个字符组成的字符串
    //     string LeftRotateString(string str, int n) {
    //         string temp;
    //         if(str=="")
    //             return temp;
    //         if(n>str.size()){
    //             n=n%str.size();
    //         }
    //         string str1=str.substr(n);
    //         temp=str1+str.substr(0,n);
    //         return temp;
    //     }
};