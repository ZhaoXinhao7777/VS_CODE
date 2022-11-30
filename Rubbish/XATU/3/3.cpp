#include<iostream>
#include<windows.h>
using namespace std;

int main()
{  
    int n;
    cin>>n;
    int arr[n][n]={1};
    int lie=1;
    for(int i=0;i<n;i++)
    {
       int hang=i+2;
       for(int j=0;j<n;j++)
       {
            arr[i][j+1]=arr[i][j]+hang;
            hang++;
       }
       arr[i+1][0]=arr[i][0]+lie;
       lie++;
    }

    //打印
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;

}