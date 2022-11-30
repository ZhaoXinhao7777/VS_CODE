//正整数的各位数字之和被Tom称为Tom数。求输入数（<2^32）的Tom数!
#include<stdio.h>
#include<math.h>
long long Add(long long n)
{
    long long temp=n,count=0;
    for(;temp>10;temp=temp/10)
    {
        count+=(temp%10);
    }
    if(temp<10)
    {
        count+=temp;
    }
    return count;
}

int main()
{
    int n;

    while(scanf("%d",&n)!=NULL)
    {
        printf("%d\n",Add(n));
    }

    system("pause");
    return 0;
}