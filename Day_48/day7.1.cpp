#include<iostream>
using namespace std;

unsigned int min(int m,int n)
{
    if(m<n)
    return m;
    else
    return n;
}
int main()
{
    unsigned int N,f0=0,f1=1;
    cin>>N;

    unsigned int count=0;
    while(1)
    {
        if(f0<=N&&f1>=N)
        {
            break;
        }

        f0+=f1;
        f1+=f0;
    }
    
    count=min(N-f0,f1-N);
    cout<<count<<endl;

    system("pause");
    return 0;

}