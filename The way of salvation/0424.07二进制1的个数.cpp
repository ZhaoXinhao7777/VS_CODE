#include <bitset>
class Solution
{
public:
    int NumberOf1(int n)
    {
        //  int count=0;
        //  while(n!=0)
        //  {
        //     //先让count++是因为先判断n不为0，那它的二进制中必有一个1
        //     count++;
        //     //n&(n-1)作用：将n的二进制表示中的最低位为1的改为0
        //     n=n&(n-1);
        //  }
        //  return count;

        // 巧用bitset
        return bitset<32>(n).count();
    }
};
#include <bitset>
// 下面是 std::bitset 类型的一些常用操作：

// size() 返回 std::bitset 的长度
// count() 返回 std::bitset 中值为 1 的位的数量
// any() 返回 std::bitset 中是否存在值为 1 的位
// none() 返回 std::bitset 中是否所有位都是 0
// all() 返回 std::bitset 中是否所有位都是 1
// test(pos) 返回 std::bitset 中位于 pos 位置的值
// set(pos) 将 std::bitset 中位于 pos 位置的值设为 1
// reset(pos) 将 std::bitset 中位于 pos 位置的值设为 0
// flip(pos) 将 std::bitset 中位于 pos 位置的值取反
// to_ulong() 返回 std::bitset 转换成的无符号整数值
// to_ullong() 返回 std::bitset 转换成的无符号长整数值