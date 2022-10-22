#include<stdio.h>
#include<windows.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main()
{
    int nums1[]={1,2,3,0,0,0};
    int nums2[]={2,5,6};

    merge(nums1,6, 3, nums2, 3, 3);

    system("pause");
    return 0;
}
// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//     int p1 = 0, p2 = 0;
//     int sorted[m + n];
//     int cur;
//     while (p1 < m || p2 < n) {
//         if (p1 == m) {
//             cur = nums2[p2++];
//         } else if (p2 == n) {
//             cur = nums1[p1++];
//         } else if (nums1[p1] < nums2[p2]) {
//             cur = nums1[p1++];
//         } else {
//             cur = nums2[p2++];
//         }
//         sorted[p1 + p2 - 1] = cur;
//     }
//     for (int i = 0; i != m + n; ++i) {
//         nums1[i] = sorted[i];
//         printf("%d ",nums1[i]);
//     }
// }

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(m==0||n==0)
    {
        return ;
    }
   
    int* arr=(int* )malloc(sizeof(int)*(m+n));
    int temp=0;
    int left=0,right=0;
    int i=0;
   while(left<m||right<n)
    {
        if (left == m) {
            temp = nums2[right++];
        } else if (right == n) {
            temp = nums1[left++];
        }else
        if(nums1[left]<nums2[right])
        {

            temp=nums1[left];
            ++left;
        }
        else
        {
            temp=nums2[right];
            ++right;
        }

        arr[left+right-1]=temp;
    }
    for(int i=0;i<(m+n);++i)
    {
        nums1[i] = arr[i];
        //printf("%d,",arr[i]);
    }
}