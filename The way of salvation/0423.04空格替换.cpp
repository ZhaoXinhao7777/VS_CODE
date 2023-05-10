void replaceSpace(char *str, int length)
{
    int spaceCount = 0;
    int totalLen = length;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
            spaceCount++;
    }
    // 从后往前进行遍历
    totalLen += spaceCount * 2;
    // 极限思考，如果数组中没有' ',则不需要进行赋值，所以totalLen!=i
    for (int i = length - 1; i >= 0 && totalLen != i; i--)
    {
        // 双指针
        if (str[i] != ' ')
            str[--totalLen] = str[i];
        else
        {
            // 逆向思维--从后往前进行赋值
            str[--totalLen] = '0';
            str[--totalLen] = '2';
            str[--totalLen] = '%';
        }
    }
}