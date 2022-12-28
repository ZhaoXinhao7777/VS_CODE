#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Memory
{
    int zoning_number; // 分区号
    char job_name;     // 作业名
    int start_address; // 起始地址
    int zoning_size;   // 分区大小
    int state;         // 状态 （0 1）   1：已分配 2：未分配
} memory;

vector<memory> me;

bool cmp(memory a, memory b)
{
    return a.start_address < b.start_address;
}

void FF() // 首次适应算法
{
    int flag = 0; // 分配成功 1  失败 0
    memory node;  // 申请新节点
    // input
    cout << "Job name (one character):";
    char name;
    cin >> name;
    node.job_name = name;
    cout << "Job memory size:";
    int u;
    cin >> u;
    node.zoning_size = u;
    // ff算法
    sort(me.begin(), me.end(), cmp); // 地址递增排序
    vector<memory>::iterator it;
    for (it = me.begin(); it != me.end(); it++)
    {
        if ((*it).state == 0) // 空闲分区链
        {
            if ((*it).zoning_size > u)
            {
                if ((*it).zoning_size - u <= 2)
                {
                    (*it).state = 1; // 将该分区从空闲链中移除
                    (*it).job_name = name;
                    flag = 1;
                    break;
                }
                else // 有空闲块能满足需求且有剩余
                {
                    node.zoning_number = (*it).zoning_number;
                    node.start_address = (*it).start_address;
                    (*it).zoning_number += 1;
                    (*it).start_address += u;
                    (*it).zoning_size -= u;
                    node.state = 1;
                    me.insert(it--, node);
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag == 1)
    {
        cout << "Distribution success!!" << endl;
    }
    else
        cout << "Allocation failure!!" << endl;
}

void recovery() // 回收内存
{
    cout << "Enter the name (one character) of the job to reclaim the partition:";
    char name;
    cin >> name;
    if (me.size() == 1)
    {
        me[0].job_name = ' ';
        me[0].state = 0;
        cout << "Recycling success!!" << endl;
        return;
    }
    for (int i = 0; i < me.size(); i++)
    {
        if (i == 0 && me[i].job_name == name)
        {
            if (me[i + 1].state == 0)
            {
                me[i].zoning_size += me[i + 1].zoning_size; // 合并 回收区与f2
                me[i].state = 0;
                me[i].job_name = ' ';
                for (int j = i + 1; j < me.size() - 1; j++)
                {
                    me[j].job_name = me[j + 1].job_name;
                    me[j].start_address = me[j + 1].start_address;
                    me[j].zoning_size = me[j + 1].zoning_size;
                    me[j].state = me[j + 1].state;
                }
                me.pop_back();
                cout << "Recycling success!!" << endl;
                break;
            }
            else
            {
                me[i].job_name = ' ';
                me[i].state = 0;
                cout << "Recycling success!!" << endl;
                break;
            }
        }
        if ((i == (me.size() - 1)) && me[i].job_name == name)
        {
            if (me[i - 1].state == 0)
            {
                me[i - 1].zoning_size += me[i].zoning_size;
                me[i - 1].job_name = ' ';
                me.pop_back();
                cout << "Recycling success!!" << endl;
                break;
            }
            else
            {
                me[i].job_name = ' ';
                me[i].state = 0;
                cout << "Recycling success!!" << endl;
                break;
            }
        }
        if (me[i].job_name == name)
        {
            if (me[i - 1].state == 0 && me[i + 1].state == 0)
            {
                me[i - 1].zoning_size = me[i - 1].zoning_size + me[i].zoning_size + me[i + 1].zoning_size;
                me[i - 1].job_name = ' ';
                for (int j = i; j < me.size() - 1; j++) // i+1->i i+2->i
                {
                    me[j].job_name = me[j + 1].job_name;
                    me[j].start_address = me[j + 1].start_address;
                    me[j].zoning_size = me[j + 1].zoning_size;
                    me[j].state = me[j + 1].state;
                }
                me.pop_back();
                for (int j = i; j < me.size() - 1; j++) // i+2->i
                {
                    me[j].job_name = me[j + 1].job_name;
                    me[j].start_address = me[j + 1].start_address;
                    me[j].zoning_size = me[j + 1].zoning_size;
                    me[j].state = me[j + 1].state;
                }
                me.pop_back();
                cout << "Recycling success!!！" << endl;
                break;
            }
            else if (me[i - 1].state == 0)
            {
                me[i - 1].zoning_size += me[i].zoning_size;
                me[i - 1].job_name = ' ';
                for (int j = i; j < me.size() - 1; j++)
                {
                    me[j].job_name = me[j + 1].job_name;
                    me[j].start_address = me[j + 1].start_address;
                    me[j].zoning_size = me[j + 1].zoning_size;
                    me[j].state = me[j + 1].state;
                }
                me.pop_back();
            }
            else if (me[i + 1].state == 0)
            {
                me[i].zoning_size += me[i + 1].zoning_size;
                me[i].job_name = ' ';
                me[i].state = 0;
                for (int j = i + 1; j < me.size() - 1; j++)
                {
                    me[j].job_name = me[j + 1].job_name;
                    me[j].start_address = me[j + 1].start_address;
                    me[j].zoning_size = me[j + 1].zoning_size;
                    me[j].state = me[j + 1].state;
                }
                me.pop_back();
            }
            else
            {
                me[i].job_name = ' ';
                me[i].state = 0;
                cout << "Recycling success!!" << endl;
                break;
            }
        }
    }
}

void menu()
{
    cout << "\n\n";
    cout << "1. Allocate memory" << endl;
    cout << "2. Reclaim memory" << endl;
    cout << "3. Display the memory usage" << endl;
    cout << "4. Quit" << endl;
    cout << "\n\n";
    cout << "Please enter select:";
}

void print() // 显示内存使用情况
{

    cout << "Partition number \t job name \t start address \t Partition size \t status" << endl;
    vector<memory>::iterator it;
    for (it = me.begin(); it != me.end(); it++)
    {
        cout << (*it).zoning_number << "\t" << (*it).job_name << "\t" << (*it).start_address << "\t\t" << (*it).zoning_size << "\t\t" << (*it).state << endl;
    }
}

int main()
{
    // 初始化头结点
    memory head;
    head.zoning_number = 0;
    head.start_address = 0;
    head.zoning_size = 1024;
    head.state = 0;

    me.push_back(head);

    int sel;
    int flag = 1;
    while (1)
    {
        menu();
        cin >> sel;
        switch (sel)
        {
        case 1:
            FF();
            break;
        case 2:
            recovery();
            break;
        case 3:
            print();
            break;
        case 4:
            flag = 0;
            break;
        }
        if (flag == 0)
            break;
    }

    system("pause");
    return 0;
}
