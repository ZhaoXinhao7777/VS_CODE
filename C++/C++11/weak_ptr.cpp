#include <iostream>
using namespace std;

#if 0
struct ListNode
{
    ListNode* next;
    ListNode* prev;
    int data;

    ListNode(int x = 0)
        :next(nullptr)
        , prev(nullptr)
        , data(x)
    {}
};
#endif

// shared_ptr的循环引用
// 导致资源泄露
// https://www.cnblogs.com/workharder/p/14405778.html
#include <memory>
struct ListNode
{
    // shared_ptr<ListNode> next;
    // shared_ptr<ListNode> prev;
    // int data;

    // ListNode(int x = 0)
    //     :next(nullptr)
    //     , prev(nullptr)
    //     , data(x)
    //{
    //     cout << "ListNode(int):" << this << endl;
    // }

    weak_ptr<ListNode> next;
    weak_ptr<ListNode> prev;
    int data;

    ListNode(int x = 0)
        : next(), prev(), data(x)
    {
        cout << "ListNode(int):" << this << endl;
    }

    ~ListNode()
    {
        cout << "~ListNode():" << this << endl;
    }
};

void TestSharedPtr()
{
    shared_ptr<ListNode> sp1(new ListNode(10));
    shared_ptr<ListNode> sp2(new ListNode(20));

    // sp.use_count();
    // 对象数据的引用计数，每次引用计数加1，每次释放计数减一，当计数为0时，释放对象空间
    cout << sp1.use_count() << endl; // 1  //1
    cout << sp2.use_count() << endl; // 1  //1

    sp1->next = sp2;
    sp2->prev = sp1;

    cout << sp1.use_count() << endl; // 2  //1
    cout << sp2.use_count() << endl; // 2  //1
}

int main()
{
    TestSharedPtr();
    //_CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}