#include<stdio.h>
 int fib(int n)
 {
     if(n<3)
     return 1;
     
     return fib(n-1)+fib(n-2);
 }
 
 int main()
 {
     int n,m,p;
     scanf("%d %d %d",&n,&m,&p);
     
         int temp=fib(n);
         temp=temp%(fib(m)-fib(m-1));
         temp%=p;
         printf("%d",temp);
         
         return 0;

 }