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
