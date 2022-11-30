//数组中出现次数超过一半的数字
int MoreThanHalfNum_Solution(int* numbers, int numbersLen ) {
    // write code here
    int num=0;//当前数字
    int count=0;//当前数字出现的次数
    for(int i=0;i<numbersLen;i++){
        if(count==0)
        {
            num=numbers[i];
            count=1;
        }
        else if(numbers[i]==num){
            count++;
        }else
            count--;
    }
    return num;
}