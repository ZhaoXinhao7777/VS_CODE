#include <stdio.h>
#include <string.h>
typedef long long ll;
typedef struct    
{
    ll a[2][2];
}matrix;
ll n,m,p;
ll fib_m; 
ll mul_mod(ll a,ll b,ll p)    //大数相乘取模
{
    ll ans=0;
    while(b)
    {
        if(b&1)
        {
            ans=ans+a;
            ans=ans%p; 
        }
        a=a<<1;
        a=a%p;
        b=b>>1;
    }
    return ans;
} 
matrix mul_mat_1(matrix first,matrix second)    //矩阵乘法 
{
    matrix result; 
    memset(result.a,0,sizeof(result.a));    //初始化
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                result.a[i][j]=(result.a[i][j]%p+mul_mod(first.a[i][k],second.a[k][j],p)%p)%p;
            }
        }
    } 
    return result;
}
matrix POW_1(matrix mat,ll n)    //矩阵mat的n次方 
{
    matrix t;
    t.a[0][0]=1;    //单位矩阵 
    t.a[0][1]=0;
    t.a[1][0]=0;
    t.a[1][1]=1;
    while(n>0)    //快速幂
    {
        if(n&1)    //如果是奇数
        {
            t=mul_mat_1(t,mat);    //等于结果乘当前的底数 
        } 
        n=n>>1;
        mat=mul_mat_1(mat,mat);    //自身平方 
    } 
    return t;
}
ll quick_fib_1(ll c)    //c代表次方数
{
    matrix mat,temp;
    memset(mat.a,0,sizeof(mat.a));
    mat.a[0][0]=1;
    mat.a[0][1]=1;
    mat.a[1][0]=1;
    temp=POW_1(mat,c);
    return temp.a[0][1];
}
matrix mul_mat(matrix first,matrix second)    //矩阵乘法 
{
    matrix result;
    memset(result.a,0,sizeof(result.a));    //初始化
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                result.a[i][j]=(result.a[i][j]+first.a[i][k]*second.a[k][j]);
            }
        }
    } 
    return result;
}
matrix POW(matrix mat,ll n)    //矩阵mat的n次方 
{
    matrix t;
    t.a[0][0]=1;    //单位矩阵 
    t.a[0][1]=0;
    t.a[1][0]=0;
    t.a[1][1]=1;
    while(n>0)    //快速幂
    {
        if(n&1)    //如果是奇数
        {
            t=mul_mat(t,mat);    //等于结果乘当前的底数 
        } 
        n=n>>1;
        mat=mul_mat(mat,mat);    //自身平方 
    } 
    return t;
}
ll quick_fib(ll c)    //c代表次方数
{
    ll ans;
    matrix mat,temp;
    memset(mat.a,0,sizeof(mat.a));
    mat.a[0][0]=1;
    mat.a[0][1]=1;
    mat.a[1][0]=1;
    temp=POW(mat,c);
    return temp.a[0][1];
}
int main()
{
    scanf("%lld %lld %lld",&n,&m,&p);
    if(m>n+2)    //如果m大于n+2，不需要计算f(m)的值 
    {
        printf("%lld",(quick_fib_1(n+2))%p-1);//可以中途模p 
        return 0;
    }
    else    //否则需要模上f(m) 
    {
        fib_m=quick_fib(m);    //算出fibm的值。这个数没办法取模，只能硬算 
        printf("%lld",(quick_fib(n+2))%fib_m%p-1);//第m项可以不优化求出来 ，所以第n+2项也可以不取模优化 
    }
    return 0;
}