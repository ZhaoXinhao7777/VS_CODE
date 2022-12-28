#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;
const int MaxNum = 100;

string name[MaxNum];     // 进程名
int ArrivalTime[MaxNum]; // 到达时间
int ServiceTime[MaxNum]; // 服务时间
int p;                   // 时间片大小
int num;                 // 进程数量

void RR(int num, int p, string name[], int ArrivalTime[], int ServiceTime[])
{
    // 时间片轮转
    int point = 0;
    int location[MaxNum]; // 对到达时间排序后的结果，其中存放的是进程所对应的数组下标
    int temp[MaxNum];     // 备份
    int i, j = 0;         // 循环控制变量
    // 对到达时间进行备份
    for (i = 0; i < num; i++)
    {
        temp[i] = ArrivalTime[i];
    }
    int FinishTime[MaxNum]; // 完成时间
    int WholeTime[MaxNum];  // 周转时间
    double totalWeightWholeTime = 0.0, totalWholeTime = 0.0;
    double WeightWholeTime[MaxNum]; // 带权周转时间
    double AverageWWT_RR = 0;       // 平均带权周转时间
    double AverageWT_RR = 0;        // 平均周转时间
    int index;
    for (i = 1; i <= num; i++)
    {
        index = 0;
        for (j = 0; i != 1 && j < num; j++)
        {
            if (temp[j] == -1)
            {
                ++index;
            }
            else
            {
                break;
            }
        }
        // 找到剩下进程中到达时间最小的进程的位置
        for (j = 0; j < num; j++)
        {
            if (temp[j] == -1)
            {
                continue;
            }
            else
            {
                if (temp[index] > temp[j])
                {
                    index = j;
                }
                else if (temp[index] == temp[j])
                {
                    if (ArrivalTime[index] > ArrivalTime[j])
                    {
                        index = j;
                    }
                }
            }
        }
        // 按序存入进程所在位置
        location[i - 1] = index;
    }
    for (i = 0; i < num; i++)
    { // 对服务时间进行备份
        temp[i] = ServiceTime[i];
    }
    i = 0;             // 时间
    queue<int> queue;  // 队列
    queue.push(point); // 先存入0，不然无法执行以下操作
    while (queue.size() > 0)
    {
        if (i == 0)
        {
            queue.pop(); // 出队
        }
        while (point != num && (ArrivalTime[point] <= i + p && ArrivalTime[point] >= i))
        {
            queue.push(point); // 在时间片内到达的，存入队列中
            ++point;
        }
        index = queue.front(); // 获取队列首部的值
        queue.pop();           // 出队
        if (temp[index] > p)
        { // 当进程剩下的服务时间大于时间片
            temp[index] -= p;
            queue.push(index);
            i += p;
        }
        else
        { // 当进程剩下的服务时间小于时间片
            FinishTime[index] = i + temp[index];
            WholeTime[index] = FinishTime[index] - ArrivalTime[index];
            WeightWholeTime[index] = double(WholeTime[index]) / ServiceTime[index];
            totalWholeTime += WholeTime[index];
            totalWeightWholeTime += WeightWholeTime[index];
            i = i + temp[index];
        }
    }
    // 得出平均周转时间和平均带权周转时间
    AverageWT_RR = totalWholeTime / num;
    AverageWWT_RR = totalWeightWholeTime / num;
    cout << "The time slice rotates:" << endl;
    cout << "Process      ";
    for (i = 0; i < num; i++)
    {
        cout << name[i] << "   ";
    }
    cout << endl
         << "Time of arrival    ";
    for (i = 0; i < num; i++)
    {
        cout << ArrivalTime[i] << "   ";
    }
    cout << endl
         << "Service time    ";
    for (i = 0; i < num; i++)
    {
        cout << ServiceTime[i] << "   ";
    }
    cout << endl
         << "Completion time    ";
    for (i = 0; i < num; i++)
    {
        cout << FinishTime[i] << "   ";
    }
    cout << endl
         << "Turnaround time    ";
    for (i = 0; i < num; i++)
    {
        cout << WholeTime[i] << "   ";
    }
    cout << endl
         << "Turnaround time with weight ";
    for (i = 0; i < num; i++)
    {
        cout << WeightWholeTime[i] << "   ";
    }
    cout << endl;
    cout << "average turnaround time is:" << AverageWT_RR << endl;
    cout << "Average turnaround time with weight:" << AverageWWT_RR << endl;
}

int main(int argc, char *argv[])
{
    int num;
    int p, i;
    string name[MaxNum];     // 进程名
    int ArrivalTime[MaxNum]; // 到达时间
    int ServiceTime[MaxNum]; // 服务时间
    cout << "Please enter the time slice size:";
    cin >> p;
    cout << "Please enter the number of processes (not greater than 100) :";
    cin >> num;
    cout << "Please enter the process name: ";
    for (i = 0; i < num; i++)
    {
        cin >> name[i];
    }
    cout << "Please enter arrival time: ";
    for (i = 0; i < num; i++)
    {
        cin >> ArrivalTime[i];
    }
    cout << "Please enter service hours:";
    for (i = 0; i < num; i++)
    {
        cin >> ServiceTime[i];
    }
    cout << endl;
    RR(num, p, name, ArrivalTime, ServiceTime);

    system("pause");
    return 0;
}
