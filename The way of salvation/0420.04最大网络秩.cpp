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
    //���������ֻ��һ���ַ�
    if (a.size() == 1)
        return true;
    //˫ָ�뷨
    int left = a.size() / 2 - 1;
    //�ж������Ƿ�Ϊ���Ĵ�
    left = min(check(a, a, left), check(b, b, left));
    //ab||ba ����Ϊ���Ĵ�
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