#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <assert.h>
#include "Common.h"

template <class T>
struct HashNode
{
    T _data;
    HashNode<T> *_next;

    HashNode(const T &data = T())
        : _next(nullptr), _data(data)
    {
    }
};
// 专门处理T是整数家族：char,short,int,long,long long
template <class T>
class T2IntDef
{
public:
    size_t operator()(const T &data)
    {
        return data;
    }
};

template <class T, class T2Int = T2IntDef<T>>
class HashBucket;

template <class T, class Ref, class Ptr, class T2Int = T2IntDef<T>>
struct HansBucketIterator
{
};

template <class T, class T2Int>
class HashBucket
{
public:
    typedef HashNode<T> Node;
    typedef HansBucketIterator<T, T &, T *, T2Int> iterator;

private:
    vector<Node *> _table;
    size_t _size;
    friend struct HansBucketIterator<T, T &, T *, T2Int>;

public:
    HashBucket(size_t capacity = 3)
        : _table(GetNextPrime(capacity)), _size(0)
    {
    }
    /* HashBucket(size_t capacity = 10)
         : _table(10)
         ,_size(0)
     {}*/

    ~HashBucket()
    {
        Clear();
    }

    // 哈希桶中元素是唯一的
    bool InsertUnique(const T &data)
    {
        CheckCapacity();

        // 1.计算桶号
        size_t bucketNo = HashFunc(data);

        // 2.确保bucketNo桶中不存在data
        Node *cur = _table[bucketNo];
        while (cur)
        {
            if (data == cur->_data)
                return false;

            cur = cur->_next;
        }

        // 单链表头插
        cur = new Node(data);
        cur->_next = _table[bucketNo];
        _table[bucketNo] = cur;
        _size++;
        return true;
    }

    // 删除所有值为data的元素
    size_t EraseEqual(const T &data)
    {
        // 1.计算桶号
        size_t bucketNo = HashFunc(data);
        size_t oldsize = _size;
        // 2.找到值为data的节点并删除
        Node *cur = _table[bucketNo];
        Node *prev = nullptr;
        while (cur)
        {

            if (data == cur->_data)
            {
                // 找到了 且data为首节点
                if (nullptr == prev)
                {
                    _table[bucketNo] = cur->_next;
                    delete cur;
                    _size--;
                    cur = _table[bucketNo];
                }
                // 节点不为首节点
                else
                {
                    prev->_next = cur->_next;
                    delete cur;
                    _size--;
                    cur = prev->_next;
                }
            }
            else
            {
                // 不是待删除节点
                prev = cur;
                cur = cur->_next;
            }
        }

        return oldsize - _size;
    }
    // 哈希表的删除
    void Clear()
    {
        for (size_t i = 0; i < _table.capacity(); i++)
        {
            Node *cur = _table[i];
            while (cur)
            {
                _table[i] = cur->_next;
                delete cur;
                cur = _table[i];
            }
        }
        _size = 0;
    }
    // 查找值为data的元素是否存在
    bool Find(const T &data)
    {
        // 1.计算桶号
        size_t bucketNo = HashFunc();

        // 2.检测是否存在
        Node *cur = _table[bucketNo];
        while (cur)
        {
            if (data == cur->_data)
            {
                return true;
            }
        }
        return false;
    }
    // 计算桶的数量
    size_t BucketCount() const
    {
        return _table.capacity();
    }
    // 元素的个数
    size_t BucketSize(size_t bucketNo) const
    {
        assert(bucketNo < BucketCount());
        Node *cur = _table[bucketNo];
        size_t count = 0;
        while (cur)
        {
            count++;
            cur = cur->_next;
        }
        return count;
    }
    // 计算桶号
    size_t Bucket(const T &data) const
    {
        return HashFunc(data);
    }
    void Swap(HashBucket<T, T2Int> &ht)
    {
        _table.swap(ht._table);
        std::swap(_size, ht._size);
    }
    size_t Size() const
    {
        return _size;
    }
    bool Empty()
    {
        return 0 == _size;
    }

public:
    void Print() const
    {
        for (size_t i = 0; i < _table.capacity(); i++)
        {
            cout << "_table[" << i << "]:";
            Node *cur = _table[i];
            while (cur)
            {
                cout << cur->_data << "->";
                cur = cur->_next;
            }
            cout << "NULL" << endl;
        }
        cout << "----------------------------" << endl;
    }

private:
    // 哈希函数 除留余数法
    size_t HashFunc(const T &data)
    {
        // return data % _table.capacity();
        // T可能是任意类型
        // 如果T不是整形，需要将data转为整形数字才能取模
        T2Int t2Int;
        return t2Int(data) % _table.capacity();
    }

    void CheckCapacity()
    {
        if (_size == _table.capacity())
        {
            // 扩容 ：按照两倍方式扩容
            HashBucket<T, T2Int> newHT(GetNextPrime(_size));

            for (size_t i = 0; i < _table.capacity(); i++)
            {
                Node *cur = _table[i];

                //  将i号桶对应的链表的每一个节点插入新哈希表中
                while (cur)
                {
                    // 1.将cur从_table[i]中拆下来
                    _table[i] = cur->_next;

                    // 2.将cur插入newTable中
                    //      1.计算新的桶号
                    size_t newBuckNo = newHT.HashFunc(cur->_data);
                    //      2.插入新桶中
                    cur->_next = newHT._table[newBuckNo];
                    newHT._table[newBuckNo] = cur;
                    newHT._size++;

                    // 3.从_table[i]中拆下来
                    cur = _table[i];
                    _size--;
                }
            }
            this->Swap(newHT);
        }
    }
};
class Str2Int
{
public:
    size_t operator()(const string &s)
    {
        const char *str = s.c_str();
        unsigned int seed = 131; // 31 131 1313 13131 131313
        unsigned int hash = 0;
        while (*str)
        {
            hash = hash * seed + (*str++);
        }

        return (hash & 0x7FFFFFFF);
    }
};
void TestHashBucket1()
{
    HashBucket<int> ht1;
    ht1.InsertUnique(1);
    ht1.InsertUnique(2);
    ht1.InsertUnique(3);
    ht1.InsertUnique(4);
    ht1.InsertUnique(11);
    ht1.InsertUnique(12);
    ht1.InsertUnique(13);
    ht1.InsertUnique(14);
    ht1.InsertUnique(44);
    ht1.InsertUnique(54);
    ht1.Print();

    ht1.InsertUnique(21);
    ht1.Print();
}

void TestHashBucket2()
{

    HashBucket<string, Str2Int> ht1;
    ht1.InsertUnique("apple"); // string s1("apple");
    ht1.InsertUnique("apple"); // string s2("apple");
    ht1.InsertUnique("orange");
    ht1.InsertUnique("grape");
    ht1.InsertUnique("pear");
    ht1.Print();
}
