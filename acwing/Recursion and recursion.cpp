#include<iostream>
#include<algorithm>
using namespace std;
#if 0
//超时 10^8
//所有递归都可以转换为一颗递归搜索树
//递归--dfs  顺序
//恢复状态
const int N=15;
int ways[1<<15][16],cnt;
int n;

int st[N];//记录每一个位置当前的状态 0表示还没考虑，1表示选它，2表示不选
void dfs(int u)
{
    if(u>n)
    {
       for(int i=1;i<=n;i++)//记录方案
            if(st[i]==1)
            ways[cnt][i]=i;
        cnt++;
    return ;
    }
    st[u]=2;
    dfs(u+1);//第一个分支 不选
    st[u]=0;//恢复现场

    st[u]=1;
    dfs(u+1);//第二个分支 选
    st[u]=1;//恢复现场
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    for(int i=0;i<cnt;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",ways[i][j]);
        puts("");
    }

    system("pause");
    return 0;
}
#endif
//9! 326880  n*n! ->dfs 
//把1~n这n个整数排成一行后随机打乱顺序，输出所有可能的次序 1<=n<=9
//字典序 两个字符串 a1,a2,,,an
//                b1,b2,,,bm 
int main()
{


    system("pause");
    return 0;
}