#include"Heap.h"
#if 0
void AdjustUp(DataType arr[],int size,int child);
void Swap(int* a, int* b);

//堆的构建
void HeapCreate(Heap* hp, DataType* a, int n, PFUNC Compare)
{
	hp->array = (DataType*)malloc(sizeof(DataType)*n);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = n;

	memcpy(hp->array, a, sizeof(DataType)*n);
	hp->size = n;
	//hp->Compare = Compare;

	// 需要从倒数第一个非叶子节点的始位置开调整
	for (int root = (n-2)/2; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}

//堆的销毁
void HeapDestory(Heap* hp)
{
    assert(hp);
    free(hp);
    hp->array=NULL;
    hp->capacity=0;
    hp->size=0;
}

void CheckHeapCapacity(Heap *hp)
{
    assert(hp);
    
    if(hp->size==hp->capacity)
    {   
        //1.申请新空间
        int newCapacity=hp->capacity*2;
        Heap* temp=(Heap*)malloc(newCapacity*sizeof(DataType));
        if(NULL==temp)
        {
            assert(0);
            return;
        }
        //2.将旧空间元素拷贝到新空间中
        memcpy(temp,hp->array,sizeof(DataType)*hp->size);

        //3.释放旧空间
        free(hp->array);
        hp->array=temp->array;
        hp->capacity=newCapacity;
    }
}
//堆的插入
void HeapPush(Heap* hp,DataType data)
{
    CheckHeapCapacity(hp);
    //1.将元素放入空间末尾
    hp->array[hp->size]=data;
    hp->size++;
    //2.再将新元素往上调整
    AdjustUp(hp->array,hp->size,hp->size-1);
}

//堆的删除
void HeapPop(Heap* hp)
{
    if(HeapEmpty(hp))
    {
            return;
    }

//  1.将堆顶元素和最后一个元素进行交换
    Swap((&hp->array[0]),(&hp->array[hp->size-1]));
//  2.将堆中有效元素个数-1
    hp->size--;
//  3.将堆顶元素往下调整
    AdjustDown(hp,0);

}

//获取堆顶元素
DataType HeapTop(Heap *hp)
{
    assert(hp);

    return hp->array[0];
}

//堆的数据个数
int HeapSize(Heap *hp)
{
    assert(hp);
    return hp->size;
}

//堆的判空
int HeapEmpty(Heap *hp)
{
    assert(hp);
    return hp->size;
}
///////////////////////////////////////////


void HeapSort(int arr[],int size)
{

}



void Swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//向下调整
void AdjustDown(Heap *hp, int parent)
{
    int size=hp->size;
    int *arr=hp->array;

    // child默认标记parent的左孩子
	// 因为：parent如果有孩子，一定是先有左孩子再有右孩子
	// 因为树是完全二叉树
    int child = parent * 2 + 1;

    while (child < size)
    {
        // 如果右孩子存在，再找parent两个孩子中较小的孩子
        if (child+1 < size && arr[child + 1] < arr[child])
        {
            child +=1;
        }

        if (arr[parent] > arr[child])
        {
            Swap(&arr[child], &arr[parent]);    
            parent = child;
            child = parent * 2 + 1;
        }else{
            return;
        }  
    }
}

//向上调整
void AdjustUp(DataType arr[],int size,int child)
{
    int parent=(child-1)/2;
    while(child)
    {
        if(arr[child]<arr[parent]){
            Swap(&arr[child],&arr[parent]);
            parent=child;
            parent=(child-1)/2;
        }else{
            return;
        }
    }
}
// void AdjustUp(Heap* hp, int child)
// {
// 	int* array = hp->array;
// 	int parent = (child - 1) / 2;

// 	while (child)
// 	{
// 		if (hp->Compare(array[child], array[parent]))
// 		{
// 			Swap(&array[child], &array[parent]);
// 			child = parent;
// 			parent = (child - 1) / 2;
// 		}
// 		else
// 		{
// 			return;
// 		}
// 	}
// }

void Test()
{
   // int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int array[] = { 49, 65, 27, 34, 19, 28, 18, 15, 25, 37 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));

	printf("size = %d\n", HeapSize(&hp));
	printf("top = %d\n", HeapTop(&hp));

	HeapPop(&hp);

	printf("size = %d\n", HeapSize(&hp));
	printf("top = %d\n", HeapTop(&hp));
	// ...

	HeapPush(&hp, 100);
	HeapPush(&hp, 15);
	HeapDestory(&hp);
   
}

int main()
{
    Test();
    system("pause");
    return 0;
}
#endif

int Less(int left,int right)
{
    return left<right;
}

int Greater(int left,int right)
{
    return left>right;
}


void Swap(DataType *left,DataType *right)
{
    int temp=*left;
    *left=*right;
    *right=temp;
}

//堆的构建
void HeapCreate(Heap* hp,DataType* arr,int n,PFUNC Compare  )
{
    hp->array=(DataType*)malloc(sizeof(DataType)*n);
   
    hp->capacity=n;

    //将arr中的元素先传入hp->array中
    memcpy(hp->array,arr,sizeof(DataType)*n);
    hp->size=n;
    hp->Compare=Compare;
//从倒数第一个非叶子节点的位置开始调整
    for(int root=(n-2)/2;root>=0;root--)
    {
        //每次从root节点开始往下调整
        AdjustDown(hp,root);
    }

        for(int i=0;i<n;i++)
    {
        printf("%d->",hp->array[i]);
    }
}

//堆的销毁
void HeapDestory(Heap* hp)
{
    assert(hp);
    free(hp->array);
    hp->array=NULL;
    hp->capacity=0;
    hp->size=0;
}

//查容量
void CheckHeapCapacity(Heap *hp)
{ 
    if(hp->size==hp->capacity)
    {  
        //1.申请新空间
        int newCapacity=hp->capacity*2;
        DataType* temp=(DataType*)malloc(sizeof(DataType)*hp->size);
        // if(NULL==temp)
        // {
        //     assert(0);
        //     return ;
        // }

        //2.拷贝
        memcpy(temp,hp->array,sizeof(DataType)*newCapacity);

        //3.释放旧空间
        free(hp->array);
        hp->array=temp;
        hp->capacity=newCapacity;
    }

}

//堆的插入
void HeapPush(Heap* hp,DataType data)
{
//0.判断空间是否已满
    CheckHeapCapacity(hp); 

//1.将元素插入堆的末尾
    hp->array[hp->size]=data;
    hp->size++;
//2.再将新元素往上调整
    AdjustUp(hp,hp->size-1);

}

//堆的删除  删除的是堆顶元素
void HeapPop(Heap *hp)
{
    // if(HeapEmpty(hp));
    // {
    //     return ;
    // }

    //交换堆顶元素和堆中最后一个元素交换
    Swap(&hp->array[0],&hp->array[hp->size-1]);
    //有效元素-1
    hp->size--;
    //将对顶元素往下调整
    AdjustDown(hp,0);

}

//获取堆顶元素
DataType HeapTop(Heap *hp)
{
    assert(hp);
    return hp->array[0];
}

//堆的数据个数
int HeapSize(Heap *hp)
{
    assert(hp);
    return (0==hp->size);
}

//堆的判空
int HeapEmpty(Heap *hp)
{
    assert(hp);
    return hp->size;
}

//O(logN) 向下调整
void AdjustDown(Heap *hp,int parent)
{
    int size=hp->size;
    int *arr=hp->array;

    int child=parent*2+1;
    while(child<size)
    {
    //如果右孩子存在 找parent中 较小/大 孩子的位置 --取决于大堆还是小堆
        if(child+1 < size && hp->Compare(arr[child+1],arr[child]))
        {
            child+=1;
        }

    //检测是否满足堆的特性
        if (hp->Compare(arr[child],arr[parent])) 
        {
            Swap(&arr[child],&arr[parent]);
            parent=child;
            child=parent*2+1;
         }else
         {
            return;
         }
    }
}

//向上调整
void AdjustUp(Heap *hp,int child)
{
    int *arr=hp->array;
    int parent=(child-1)/2;

    while(child)
    if(hp->Compare(arr[child],arr[parent]))
    {
        Swap(&arr[child],&arr[parent]);
        child=parent;
        parent=(child-1)/2;
    }else{
        return ;
    }
}
//相较于向下调整，向上调整相对简单
//因为在向上调整时，其原有序列已经有序，仅需一个劲往上比较即可，遇到条件合适，即刻退出函数

void TestHeap()
{
    int arr[]={2,7,5,9,1,6,3,8,4};
    Heap hp;
    int size=sizeof(arr)/sizeof(arr[0]);

    //注意此处第四个参数 利用函数指针来确定创建的是大堆（Greater）还是小堆(Less)
    HeapCreate(&hp,arr,size,Greater);

    printf("size=%d\n",HeapSize(&hp));
    printf("HeapTop=%d\n",HeapTop(&hp));
    
    HeapPop(&hp);
    printf("HeapTop=%d\n",HeapTop(&hp));

    HeapPush(&hp,10);
    printf("HeapTop=%d\n",HeapTop(&hp));
    HeapPush(&hp,0);
    HeapPush(&hp,20);
    HeapPush(&hp,15);

    //.....
    HeapDestory(&hp);
}

int main()
{
    TestHeap();

    system("pause");
    return 0;
}