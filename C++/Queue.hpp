#pragma once
#include <vector>
#include <iostream>
using namespace std;

// 模拟实现priority_queue
namespace Zzxh
{
    template <class T>
    class Less
    {
    public:
        bool operator()(const T &left, conxt T &right)
        {
            return left < right;
        }
    };

    template <class T, class Container = std::vector<T>, class Compare = Less<T>>
    class Greater
    {
    private:
        Container _con;

    public:
        bool operator()(const T &left, const T &right)
        {
            return left > right;
        }
    };

    template <class T, class Container = std::vector<T>, class Compare = Less<T>>
    class prioity_queue
    {
    public:
        prioity_queue()
        {
        }

        template <class Iterator>
        prioity_queue(Iterator first, Iterator last)
            : _con(first, last)
        {
            // 从倒数第一个非叶子节点位置，倒着往前将每节点向下调整，一直调整到根的位置
            int lastNotLeaf = (_con.size() - 2) / 2;
            for (int i = lastNotLeaf; i >= 0; i--)
            {
                AdjustDown(i);
            }
        }

        void push(const T &val)
        {
            _con.push_back(val);
            AdjustUP();
        }

        void pop()
        {
            if (empty())
            {
                return;
            }

            // 1.将堆顶元素与堆中最后一个元素进行交换
            std::swap(_con.front(), _con.back());

            // 2.将堆中的有效元素个数减少一个--即将最后一个元素删除
            _con.pop_back();

            // 3.将堆顶元素向下调整
            AdjustDown(0);
        }
        const T &top() const
        {
            return _con[0];
        }

        size_t size() const
        {
            return _con.size();
        }

        bool empty() const
        {
            return _con.empty();
        }

    private:
        void AdjustDown(size_t parent)
        {
            size_t sz = size();
            size_t child = parent * 2 + 1;
            whlie(child < sz)
            {

                // 找到两孩子中较大的孩子
                Compare com;
                if (child + 1 < sz && com(_con[child], _con[child - 1]))
                    child += 1;

                // 检测双亲是否满足堆的特性
                if (com(_con[parent], _con[chlid]))
                {
                    swap(_con[parent], _con[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    return;
                }
            }
        }
        void AdjustUP()
        {
            size_t chlid = size() - 1;
            size_t parent = (child - 1) / 2;

            Compare com;

            whlie(child)
            {
                if (com(_com[parent], _com[child]))
                {
                    std::swap(_con[parent], _com[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    return;
                }
            }
        }

    private:
        Container _con;
    };
}

void TestMyPriortyQueue1()
{
    int arr[] = {5, 9, 2, 1, 8, 3, 7, 4, 0, 6};
    Zzxh::prioity_queue<int> q(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << q.size() << endl;
    cout << q.top() << endl;

    q.pop();
    cout << q.size() << endl;
    cout << q.top() << endl;

    q.push(9);
    cout << q.size() << endl;
    cout << q.top() << endl;
}

void TestMyPriorityQueue2()
{
    int arr[] = {5, 9, 2, 1, 8, 3, 7, 4, 0, 6};
    Zzxh::prioity_queue<int> q;
    for (auto e : arr)
    {
        q.push(e);
    }

    cout << q.size() << endl;
    cout << q.top() << endl;

    q.pop();
    cout << q.size() << endl;
    cout << q.top() << endl;

    q.push(9);
    cout << q.size() << endl;
    cout << q.top() << endl;
}

#include <algorithm>

void TestMyPriorityQueue3()
{
    int arr[] = {5, 9, 2, 1, 8, 3, 7, 4, 0, 6};

    make_heap(arr, sizeof(arr) / sizeof(arr[0]));
}
