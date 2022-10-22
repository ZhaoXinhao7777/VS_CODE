#include<assert.h>
#include<string.h>
#include<stdio.h>
#include"windows.h"
#include<stdlib.h>

typedef int DataType;
typedef int(*PFUNC)(int left, int right);

typedef struct Heap
{
    DataType* array;
    int capacity;
    int size;
    PFUNC Compare;
}Heap;

//堆的构建
void HeapCreate(Heap* hp,DataType* arr,int n,PFUNC Compare);

//堆的销毁
void HeapDestory(Heap* hp);

//堆的插入
void HeapPush(Heap* hp,DataType data);

//堆的删除
void HeapPop(Heap* hp);

//获取堆顶元素
DataType HeapTop(Heap *hp);

//堆的数据个数
int HeapSize(Heap *hp);

//堆的判空
int HeapEmpty(Heap *hp);
///////////////////////////////////////////
void TestHeap();
void HeapSort(int arr[],int size);
void AdjustDown(Heap *hp,int parent);
void AdjustUp(Heap *hp,int child);