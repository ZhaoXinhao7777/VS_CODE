// 都说程序猿不好找妹子（不过我校的学弟学妹们可以问问学长关于鞍山GQ和志愿者的故事，以及GC把妹子发展成ACMer的故事 大连交通的传奇故事哦。真的励志~）
// 一天，我校ACM协会的一个学弟想要用程序员的方式给一位妹子表白。想写程序打印个"I love U"
// 但这个字母U实在难倒了他，于是找我们的会长TL帮忙，可TL会长琐事缠身，你能替TL帮助这位学弟吗？
#include<stdio.h>

void Print(int n)
{

    for(int j=0;j<n;j++)
    {

    
    int temp=n;
    printf("*");
    for(int i=0;i<temp;i++)
    {
        printf(" ");
    }
    printf("*");
    printf("\n");
    }
    for(int i=0;i<2+n;i++)
    {
        printf("*");
    }
      printf("\n");
}
int main()
{
    int n;
    while(scanf("%d",&n)!=-1/EOF)
    {
        Print(n);
        printf("\n");
    }
    return 0;
}