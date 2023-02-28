#include <iostream>
#include <vector>
using namespace std;
#if 0
void TestVector(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // for(auto it:v)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
}

int main()
{
    vector<int> v = { 1,2,3,4,5 };
    TestVector(v);
    system("pause");
    return 0;
}
#endif

#include <vector>

#include <string>
#if 0
void TestVector1()
{
    vector<int> v1;
    vector<int> v2(10, 5); // 用10个值为5的元素构造vector

    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v3(arr, arr + sizeof(arr) / sizeof(arr[0]));

    string s("hello");
    vector<char> v4(s.begin(), s.end());
    vector<int> v5(v3);

    // vector的遍历
    // 方式1：for+下标-->推荐
    for (size_t i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    // 方式2：范围for
    for (auto e : v3)
    {
        cout << e << " ";
    }
    cout << endl;

    // 方式3：迭代器
    // vector<char>::iterator it = v4.begin();
    auto it = v4.begin();
    while (it != v4.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    // vector<int>::reverse_iterator rit = v5.rbegin();
    auto rit = v5.rbegin();
    while (rit != v5.rend())
    {
        cout << *rit << " ";
        rit++;
    }
    cout << endl;

    // C++11中，vector还增加了列表方式的构造
    vector<int> v6{1, 2, 3, 4, 5, 6};
}
/*
void resize(size_t newsize, const T &val = T())
假设vector中的旧元素个数为oldsize,当前容量为capacity
当元素增多时：
1.多出的元素需要使用val进行填充
2.当newsize>capacity时，resize需要进行扩容

当元素缩减时：
3.仅仅时有效元素个数缩减了，底层空间大小不会发生改变
*/

void TestVector2()
{
    vector<int> v{1, 2, 3, 4, 5};
    v.reserve(20);

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.resize(10, 6); // 元素新增到10个，多出的用6填充 -->无效扩容

    v.resize(30, 8);

    v.resize(50);

    // 元素个数缩小 size减小，capacity不变
    v.resize(40);
    v.resize(30);
    v.resize(20);
    v.resize(10);
}
// void reserve(size_t newcapacity);扩容
// 只会将空间增大，并不会将空间缩小
// 注意：在扩容时，一定不会改变有效元素的个数
void TestVector3()
{
    vector<int> v{1, 2, 3, 4, 5};
    v.reserve(10);
    v.reserve(20);
    v.reserve(50);
    v.reserve(70);

    v.reserve(45);
    v.reserve(23);
    v.reserve(16);
    v.reserve(10);
    v.reserve(5);
}

// 元素访问
void TestVector4()
{
    vector<int> v{1, 2, 3, 4, 5};
    cout << v[0] << endl;

    // cout << v[5] << endl;
    // cout << v.at(5) << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
}

// 1.push_back尾插
// 2.演示：vector的扩容方法：vs中是按照1，5倍方式扩容 linux下是2倍
// 3.一般情况下尽量避免：一边插入一边扩容，效率低
//     a.申请新空间
//     b.拷贝元素
//     c.释放旧空间
// 推荐：如果么美好预估vector中大概要放多少个元素可以提前将底层空间大小设置好
void TestVector5()
{
    vector<int> v;
    v.reserve(5);
    size_t cap = v.capacity();
    for (size_t i = 0; i < 100; i++)
    {
        v.push_back(i);
        if (cap != v.capacity())
        {
            cap = v.capacity();
            cout << cap << endl;
        }
    }
}
void TestVector6()
{
    vector<int> v;
    v.reserve(10);
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 时间复杂度：O(N)
    v.insert(v.begin(), 100); // begin及其后的所有元素都需要整体往后搬移

    // 在第一个5的位置插入10个8
    auto pos = find(v.begin(), v.end(), 5);
    if (pos != v.end())
    {
        v.insert(pos, 10, 8);
    }

    int arr[] = {100, 200, 300, 400, 500};
    // 将数组中的元素插入vector的末尾
    v.insert(v.end(), arr, arr + sizeof(arr) / sizeof(arr[0]));
}
void TestVector7()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    v.erase(v.begin());

    v.erase(v.begin(), v.begin() + 5);

    v.clear(); // v.erase(v.begin(),v.end());
}

///////////////////////////////////////////////////
// 迭代器失效
// 1.所有可能会引起扩容的操作都可能会导致迭代器失效
void TestVector8()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    auto it = v.begin();

    // v.insert(v.begin(), 10, 5);
    // v.resize(20, 8);

    v.reserve(20);

    // 所有可能导致迭代器失效的操作之后如果需要继续使用迭代器
    // 需要给迭代器重新赋值
    it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}
// 2.erase(pos);删除之后pos继续后序的元素都失效了
void TestVector9()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    auto it = find(v.begin(), v.end(), 5);

    if (it != v.end())
    {
        // erase的返回值：返回删除位置下一个位置的元素
        it = v.erase(it);
    }
    cout << *it << endl;
}
void TestVector10()
{
    vector<int> v{1, 2, 3, 2, 2, 6, 0, 6, 7, 3, 2, 9, 2, 1, 2};
    // 删除所有值为2的元素
    auto it = v.begin();
    while (it != v.end())
    {
        if (*it == 2)
        {
            it = v.erase(it);
        }
        else
        {
            it++;
        }
    }
}
void TestVector11()
{
    string s("hello");
    auto it = s.begin();

    while (it != s.end())
    {
        s.erase(it);
        it++;
    }
}
int main()
{
    // TestVector1();
    // TestVector2();
    // TestVector3();
    // TestVector4();
    // TestVector5();
    // TestVector6();
    // TestVector7();
    // TestVector8();
    // TestVector9();
    // TestVector10();
    TestVector11();
    system("pause");
    return 0;
}
#endif

// vector的二维构造
// 矩阵：每一行元素个数相等
void TestVector()
{
    // 需要构造5行6列的二维数组
    vector<vector<int>> vv1;
    vv1.resize(5);
    for (size_t i = 0; i < vv1.size(); i++)
    {
        vv1[i].resize(6, 8);
    }
    vector<vector<int>> vv2;
    vv2.resize(5, vector<int>(6, 8));
}
// 每行元素不同
//  例如：杨辉三角
//  1
//  1 1
//  1 2 1
//  1 3 3 1
//  1 4 6 4 1
//  ...
void TestVector2(int n)
{
    vector<vector<int>> vv(n);
    for (size_t i = 0; i < vv.size(); i++)
    {
        vv[i].resize(i + 1, 1);

        for (size_t j = 1; j < i; j++)
        {
            vv[i][j] == vv[i - 1][j] + vv[i - 1][j - 1];
        }
    }
}

int main()
{
    // TestVector();
    TestVector2(5);
    system("pause");
    return 0;
}

// 2022 12 31
