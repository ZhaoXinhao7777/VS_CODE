#include<iostream>
using namespace std;
// int main()
// {
//     int **a[3][4];
//     cout<<sizeof(**a[3][4])<<endl;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     // char a[10]={'1','2','3','4','5','6','7','8','9',0},*p;
//     // int i=8;
//     // p=a+i;
//     // cout<<p-3<<endl;
//     int n=0;
//     char ch;
//     for(ch=getchar();ch='\n';)
//     {
//         n++;
//     }
//     cout<<n<<endl;


//     system("pause");
//     return 0;
// }

int main()
{   
    char str[255];
    int i=0,j=0;
    cin>>str;
    //cout<<"----"<<str<<endl;
    int size=sizeof(str);
    int strlen=0;
    for(int i=0;str[i]!='\0';i++)
    {
        int count=0;
        for(;str[i]>='0'&&str[i]<='9';i++)
        {
            count++;
            if(str[i]=='\0')
            {
                break;
            }
        }
        if(count>strlen)
        {
            j=i;
            strlen=count;
        }

    }
    for(int i=j-strlen;i<j;i++)
    {
        cout<<str[i];
    }
    cout<<endl;
    


    system("pause");
    return 0;
}