#include<iostream>
#include<string>
using namespace std;

int check(string str1, string str, int left)
{
    int right = str1.size() - left - 1;
    while (left >= 0 && right <= str1.size())
    {
        if (str1[left] != str[right])
            break;
        left--;
        right++;
    }
    return left;
}

bool checkPalindromeFormation(string a, string b) {
    //特殊情况：只有一个字符
    if (a.size() == 1)
        return true;
    //双指针法
    int left = a.size() / 2 - 1;
    //判断自身是否为回文串
    left = min(check(a, a, left), check(b, b, left));
    //ab||ba 否则不为回文串
    left = min(check(a, b, left), check(b, a, left));
    return left == -1;
}



int main()
{
    string a = "abcde";
    string b = "ggggg";
    cout<<checkPalindromeFormation(a, b);

    system("pause");
    return 0;
}