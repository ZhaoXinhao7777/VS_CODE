//回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。
//现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。
#include<iostream>
#include<windows.h>
using namespace std;
int func(string arr,int len)
{
    
}
int main()
{
    int len;
    cin>>len;
    string arr;
    cin>>arr;

    int i=0;
    while(i<len)
    {
        if('A'<=arr[i]<'Z')
        {
            cout<<"Impossible"<<endl;
            return 0; 
        }
    }
    func(arr,len);


    system("pause");
    return 0;
}