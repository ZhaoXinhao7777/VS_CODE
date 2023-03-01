#include <iostream>
#include <algorithm>
using namespace std;
#include <list>
#include <vector>

void TestList1()
{
    list<int> L1;
    list<int> L2(10, 5);

    vector<int> v{1, 2, 3, 4, 5};
    list<int> L3(v.begin(), v.end());

    list<int> L4(L3);

    list<int> l5{1, 2, 3, 4, 5};

    // 范围for
    for (auto e : L2)
    {
        cout << e << " ";
    }
    cout << endl;

    // 迭代器
    auto it = L3.begin();
    while (it != L3.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    auto rit = L4.rbegin();
    while (rit != L4.rend())
    {
        cout << *rit << " ";
        rit++;
    }
    cout << endl;
}
void TestList2()
{
    list<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_back(6);

    cout << L.size() << endl;
    cout << L.front() << endl;
    cout << L.back() << endl;

    L.front() = 100;
    L.back() = 600;

    L.pop_back();
    L.pop_back();

    cout << L.size() << endl;
    cout << L.front() << endl;
    cout << L.back() << endl;

    L.push_front(0);
    cout << L.size() << endl;
    cout << L.front() << endl;
    cout << L.back() << endl;

    L.pop_front();
    cout << L.size() << endl;
    cout << L.front() << endl;
    cout << L.back() << endl;
}

template <class T>
void PrintList(const list<T> &L)
{
    for (auto e : L)
    {
        cout << e << " ";
    }
    cout << endl;
}
void TestList3()
{
    list<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_back(6);

    auto pos = L.begin();
    L.insert(pos, 0);
    PrintList(L);
    cout << *pos << endl;
    // 注意：list中的任意位置插入不会导致任何迭代器失效

    // 在链表中国值为data的节点前插入10个值为5的元素
    int data = 0;
    cin >> data;

    // pos = L.begin();
    // while (pos != L.end())
    // {
    //     if (*pos == data)
    //     {
    //         break;
    //     }
    //     pos++;
    // }

    pos = find(L.begin(), L.end(), data);

    if (pos != L.end())
    {
        L.insert(pos, 10, 5);
        PrintList(L);
    }
}

void TestList4()
{
    list<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_back(6);
    L.push_back(7);

    auto pos1 = L.begin();
    auto pos2 = find(L.begin(), L.end(), 5);

    cout << *pos2 << endl;

    L.erase(pos1);
    PrintList(L);

    cout << *pos2 << endl;
    // cout << *pos1 << endl;

    L.erase(L.begin(), L.end());
    if (L.empty())
    {
        cout << "L is empty!" << endl;
    }
}

bool IsEven(int data)
{
    return 0 == (data & 0x01);
}

bool Is3(int data)
{
    return 0 == data % 3;
}

void TestList5()
{
    list<int> L{1, 2, 3, 2, 4, 2, 6, 6, 8, 2, 0, 2, 3, 9, 7, 5, 2};
    L.remove(2);
    PrintList(L);

    // 删除所有偶数
    L.remove_if(IsEven);
    PrintList(L);

    // 删除所有3的倍数
    L.remove_if(Is3);
    PrintList(L);
}

void TestList6()
{
    list<int> L{1, 2, 2, 2, 3, 4, 2, 6, 4, 5, 9, 0, 7, 5, 2, 2, 4, 0, 9};
    L.sort();
    // 注意：unique之前，必须保证list中的元素是有序的
    // 可以通过list内部sort的2方式进行排序
    // sort()默认是按升序的方式排序的
    L.unique();

    PrintList(L);
}

bool Compare(int left, int right)
{
    return left > right;
}
void TestList7()
{
    list<int> L{1, 2, 2, 2, 3, 4, 2, 6, 4, 5, 9, 0, 7, 5, 2, 2, 4, 0, 9};

    // l.sort();//sort默认按照升序排序
    L.sort(Compare);
    PrintList(L);
}

void TestList8()
{
    list<int> L1{3, 4, 1, 6, 8};
    list<int> L2{0, 2, 5, 9, 7};
    L1.sort(Compare);
    L2.sort(Compare);

    L1.merge(L2); // 拼接两个有序的链表? 按升序？
    PrintList(L1);

    L1.reverse(); // 逆序
    PrintList(L1);
}
void TestListIterator1()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
    auto it = l.begin();
    while (it != l.end())
    {
        it = l.erase(it);
    }
}
int main()
{
    // TestList1();
    // TestList2();
    TestList3();
    TestList4();
    TestList5();
    TestList6();
    TestList7();
    TestList8();

    system("pause");
    return 0;
}