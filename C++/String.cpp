#include <iostream>
using namespace std;
#if 0
// string头文件，注意：STL种的头文件都没有.h
#include <string>
// string对象的构造
void TestString1()
{
    string s1;
    string s2("hello world");
    string s3(s2);
    string s4(10, 'A');

    // string的对象可以直接使用cout来进行打印
    cout << s2 << " " << &s2 << endl;
    cout << s3 << " " << &s3 << endl;
    cout << s4 << endl;
}
// string：就是动态类型的顺序表-->元素的类型是char
void TestString2()
{
    string s("hello man");
    // size();获取有效元素的个数
    cout << s.size() << endl;
    // length();获取有效元素个数
    cout << s.length() << endl;
    cout << s.capacity() << endl;

    if (!s.empty())
    {
        cout << "s is not empty! " << s << endl;
    }
    else
    {
        cout << "s is empty" << endl;
    }
}

// reserve(size_t mewcapcaity);扩容
void TestString3()
{
    string s("hello");

    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(20);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(35);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(60);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(100);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(80);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(50);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(30);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(20);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(16);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(15);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    s.reserve(10);
    cout << s.size() << endl;
    cout << s.capacity() << endl;
}
int main()
{
    // TestString1();
    // TestString2();
    TestString3();
    system("pause");
    return 0;
}
#endif
#
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#if 0
// 比较vector与list的效率
int main()
{
    srand(time(0)); // 随机数种子
    const int N = 100000;

    for (int a = 0; a < 10; ++a)
    {
        list<int> lt2;
        vector<int> v;
        v.reserve(N);
        for (int i = 0; i < N; i++)
        {
            auto e = rand();
            v.push_back(e);
            lt2.push_back(e);
        }
        int begin1 = clock();
        sort(v.begin(), v.end());
        int end1 = clock();

        int begin2 = clock();
        lt2.sort();
        // sort(lt2.begin(),lt2.end());
        int end2 = clock();
        printf("vector sort:%d\n", end1 - begin1);
        printf("list sort:%d\n", end2 - begin2);

        cout << "======================" << endl;
    }
    system("pause");
    return 0;
}
#endif

// 详情见：E:\Vs2022\救赎之道\救赎之道\String.cpp
// 仅限于vs中 ，vs code并不是这样的
void TestString3()
{
    string s("hello");
    // 通过reserve（size_t newCapacity）将string底层的空间扩大
    // 假设string底层旧空间的大小为oldCapacity
    // 如果newCapacity > oldCapacity  确实会完成扩容操作 扩容具体做法:
    //  string类内部会按照一定的机制根据用户所传递的容量去计算新空间的大小
    //  扩容机制：开辟新空间，拷贝元素，释放就空间
    //

    s.reserve(20);
    s.reserve(40);
    s.reserve(70);
    s.reserve(110);

    // 如果newCapacity <= oldCapacity &&newCapacity>=16
    //  reserve会忽略本次操作，既不会将扩容缩小

    s.reserve(80);
    s.reserve(50);
    s.reserve(30);
    s.reserve(17);
    s.reserve(16);

    // newCapacity <16 && 有效元素个数小于16 ,reserve才会将空间大小减小为15
    s.reserve(15);
    s.reserve(10);
    s.reserve(5);
    // 否则reserve直接忽略本次操作
    string AA(50, 'A');
    AA.reserve(10);
}

// 注意：string是在2019下验证的
//  为什么newCapacity小于16时，reserve才会真正将空间缩小
//
//  VS使用的STL版本中，PJ版本
//  string对象内部包含了一个固定大小的数组-->char buf[16]
//   原因：绝大多数情况下，字符串中的有效个数都是小于16的，
//   直接使用固定大小的数组，不从堆上开辟空间可以让string效率更高
//  当有效元素个数超过16时，string才会真正从堆上开辟空间
//  从堆上开辟空间是有时间消耗的，所有string类从堆上申请空间后一般不轻易缩小空间
//

// resize();
// void resize(size_t n);
// void resize(size_t n, char c);
//  将字符串大小调整为n个字符的长度
//  1.如果n小于当前字符串长度，则当前值将缩短为第一个n的值，并删除第n个字符以外的字符
//  2.如果n大于当前字符串长度，则在末尾插入所需数量的字符以达到n大小来扩展当前内容，
//    如果指定c，则新元素初始为c的副本，否则为空字符
void TestString4()
{
    string s("hello");
    s.resize(10, 'A');
    s.resize(20, 'B');
    s.resize(40, 'C');

    s.resize(30);
    s.resize(20);
    s.resize(17);
    s.resize(16);
    s.resize(15);
    s.resize(5);
}
void TestString5()
{
    string s("hello man");
    cout << s[0] << " " << s[7] << endl;
    s[0] = 'H';
    cout << s << endl;

    // 越界：assert()触发
    cout << s[10] << endl;
}

void TestString6()
{
    string s("hello man");
    cout << s.at(0) << endl;

    s.at(0) = 'H';
    cout << s << endl;

    // 越界：抛出 out_of_range异常
    cout << s.at(17) << endl;
}

void TestString7()
{
    string s("hello");
    // s.push_back(" ");
    s.push_back('@');

    s += "world";
    string ss("!!!");
    s += ss;
    s += '$';
    cout << s << endl;
}
// append
void TestString8()
{
    string s("hello");
    s.append(1, ' ');
    s.append("world");

    string ss("!!!");
    s.append(ss);

    s.append(5, '^');
    cout << s << endl;

    string str("123456");
    s.append(str, 1, 3);
    cout << s << endl;
}
// insert
void TestString9()
{
    string s("hello");

    s.insert(0, 3, 'A');
    s.insert(0, "good morning");

    string ss("ABCD");
    s.insert(7, ss);
    s.insert(s.begin(), ss.begin(), ss.end());
    cout << s << endl;
}
// erase
void TestString10()
{
    string s("hello world");
    s.erase(0, 6);
    cout << s << endl;

    s.erase(s.begin() + 2);
    cout << s << endl;

    s.erase(s.begin(), s.end()); // s.clear();
    cout << s << endl;
    cout << "___" << endl;
}

// 借助push_back方法演示string的扩容机制
// Vs code中是2倍扩容
void TestString11()
{
    string s;
    size_t cap = 0;
    for (size_t i = 0; i < 300; i++)
    {
        s.push_back('A');
        if (cap != s.capacity())
        {
            cap = s.capacity();
            cout << cap << endl;
        }
    }
}
void TestString12()
{
    string s;
    s.reserve(300);
    size_t cap = s.capacity();
    for (size_t i = 0; i < 300; i++)
    {
        s.push_back('a');
        if (cap != s.capacity())
        {
            cap = s.capacity();
            cout << cap << endl;
        }
    }
}

void TestString13()
{
    string s("1234567890");
    // string遍历
    // 推荐使用下标：for + 下标的方式
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;

    // 其次使用范围for
    for (auto e : s)
    {
        cout << e;
    }
    cout << endl;

    // 也可使用迭代器遍历，不过针对string，一般不推荐使用迭代器
    // string::iterator it=s.begin();

    // C++11
    auto it = s.begin();
    while (it != s.end())
    {
        cout << *it;
        it++;
    }
    cout << endl;

    // // C++11
    // 报错？段错误
    // auto rit = s.end();
    // while (rit != s.begin())
    // {
    //     cout << *rit;
    //     rit++;
    // }
    // cout << endl;
}

// 2022 12 06-281
#include <algorithm>
// string在遍历时候，很少使用迭代器
// 迭代器更多时候和算法结合
void TestString14()
{
    string s("1234567890");
    cout << s << endl;

    // 对字符串s进行整体逆置
    reverse(s.begin(), s.end());
    cout << s << endl;

    sort(s.begin(), s.end());
    cout << s << endl;
}
void TestString15()
{
    string s("12345");
    int ret = atoi(s.c_str());
    cout << ret << endl;
}

void TestString16()
{
    string s("121416719210");
    // 找到字符串中所有的1，将其替换为0
    //  for(int i=0;i<s.size();i++)
    //  {
    //      if(s[i]=='1')
    //      {
    //          s[i]=='0';
    //      }
    //  }

    size_t pos = 0;
    while (1)
    {
        pos = s.find('1', pos);
        if (pos == string::npos) //?
        {
            break;
        }
        s[pos] = '0';
        pos++;
    }
    cout << s << endl;
}

// 需求：获取文件的后缀-->文件名中最后一个点之后的内容
void TestString18()
{
    string s("1234.txt.cpp");
    size_t pos = s.rfind('.') + 1;
    string postFix = s.substr(pos);
    cout << postFix << endl;
}

// 给你多行单词，获取每行单词最后一个单词的长度，每行单词和单词之间以空格隔开
//  hello world
//  apple banana pear
//  one two

// string substr(suze_t pos=0,size_t len=npos)const;
void GetLastWordLenght()
{
    string s;
    // while(cin>>s)//注意:cin是以空白字符为分割的，例如空格，Tab,回车
    while (getline(cin, s))
    {
        size_t start = s.rfind(' ') + 1;
        string word = s.substr(start); // substr
        cout << word.size() << endl;
    }
}
void TestString19()
{
    string s1("abc");
    string s2("defg");

    if (s1 < s2)
    {
        cout << "s1<s2" << endl;
    }
    else if (s1 > s2)
    {
        cout << "s1>s2" << endl;
    }
    else
    {
        cout << "s1==s2" << endl;
    }
}

class Solution
{
public:
    string addString(string num1, string num2)
    {
        // 1.找位数较多的
        int Lsize = num1.size();
        int Rsize = num2.size();
        if (Rsize > Lsize)
        {
            num1.swap(num2);
            swap(Lsize, Rsize);
        }
        // num1的位数一定大于num2的位数

        // 2.设置保存结果的字符串
        string ret(Lsize + 1, '0');

        // 3.模拟实现加法
        int step = 0;
        for (int idx1 = Lsize - 1, idx2 = Rsize - 1; idx1 >= 0; idx1--, idx2--)
        {
            // 获取左操作数的每一位
            int val = num1[idx1] - '0'; // 0的ascii为48

            // 如果num2中有数字
            if (idx2 >= 0)
            {
                val += num2[idx2] - '0';
            }

            // 加上一次的进位
            val += step;

            // 考虑本次加法是否需要进位
            step = 0;
            if (val >= 10)
            {
                step = 1;
                val -= 10;
            }
            ret[idx1 + 1] += val;
        }
        if (step == 1)
        {
            ret[0] += 1;
        }
        else
        {
            ret.erase(ret.begin()); // ret.erase(0,1);
        }
        return ret;
    }
};

void TestAddNum()
{
    string s1("456");
    string s2("77");

    Solution s; //??Solution??
    string ret = s.addString(s1, s2);
    cout << ret << endl;
}
int main()
{
    // TestString3();
    // TestString4();
    // TestString5();
    // TestString6();
    // TestString7();
    // TestString8();
    // TestString9();
    // TestString10();
    // TestString11();

    // TestString12();
    TestString13();
    TestString14();
    TestString15();
    TestString16();
    // TestString17();
    TestString18();
    TestString19();

    TestAddNum();
    // string s1;
    // string s2("Hello World");
    // cout << s2 << endl;
    // string s3(s2);

    // const char *p = "HeyMan";
    // string s4(p, p + 4);
    // cout << s4 << endl;

    // // 注意
    // // cin和cout都支持string类型对象的输入和输出
    // cin >> s1;
    // cout << s1 << endl;
    // cout << s2.size() << endl;
    system("pause");
    return 0;
}
