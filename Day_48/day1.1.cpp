// #include<iostream>
// using namespace std;

// int sort(int arr[], int len) {
//     int i, j, temp;
//     for (i = 0; i < len - 1; i++)
//         for (j = 0; j < len - 1 - i; j++)
//             if (arr[j] > arr[j + 1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//     return arr[1];
// }
// int main()
// {
//     int n=0;
//     cin>>n;
//     int temp=n;
//     int count=0;
//     while(1)
//     {
//         int i=0;
//         int arr[3]={0};
//         while(i<3)
//         {
//             cin>>arr[i];
//             i++;
//         }
//         count+=sort(&arr[0],3);
    
//         temp--;
//         if(temp==0)
//             break;
//     }

//     cout<<count<<endl;
//     system("pause");
//     return 0;
// }

#include <stdio.h>
#include<windows.h>
int main(void) {
printf("%s , %5.3s\n", "computer", "computer");

//5.3s，输出占5列，只取该字符串的左端3个字符，不足5列在左边补空格
system("pause");
return 0;
}