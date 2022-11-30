//
#include<stdio.h>
#include<windows.h>
#include<string.h>

int judge(char temp[])
{
    int len=strlen(temp);
    //printf("%d\n",len);
    int i=0,j=len-1;
    while(i<j)
    {

        if(temp[i]!=temp[j])
        {
            return 0;
        }
        i++;
        j--;
        
    }
    return 1;
}
int main()
{
    char A[100],B[100];
    scanf("%s %s",A,B);
    int strlen_A=strlen(A);
    
    int i=0;
    int count=0;
    while(1)
    {  
        
        char temp[200];
        //将拷贝到temp中，利用temp做文章
        strcpy(temp,A);
        //遍历插入--不会用insert()
        strcpy(&temp[i],B);
        strcat(temp,&A[i]);
        i++;
        printf("temp:%s\n",temp);
        count+=judge(temp);
        
        //退出条件
        if(strlen_A<i)
        {
            break;
        }
    }    
    printf("%d\n",count);
    system("pause");
    return 0;
}