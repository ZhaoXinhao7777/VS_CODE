//string字符串转数字
//90%通过率
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

    int  StrToInt(string str) {
    int len=str.length();
    char arr[100]={'0'};
    int count=0;
    //cout<<len<<endl;
    int i=0;
    // cout<<str[0]<<endl;
    //printf("%d %d\n",'+','-');
    arr[0]=str[0];
    if(arr[0]==43||arr[0]==45)
    {
        i++;
    }

    for(;str[i]!='\0';i++)
    {
        arr[i]=str[i];
        //printf("%d ",arr[i]);
        if(arr[i]<48||arr[i]>57)
        {
            count=0;
            break;
        }        
        count+=((int)arr[i]-48)*pow(10,len-2);
        len--;
    }
     
    if(arr[0]==45)
    count=-count;

    return count;
}

int main()
{
    char arr[100]="\"hello\"";

    string str;
    cin>>str;
    cout<<StrToInt(str)<<endl; 
    system("pause");
    return 0;


}