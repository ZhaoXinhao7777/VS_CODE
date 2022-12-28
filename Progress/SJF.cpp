#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct PCB
{
    int no;
    char name[10];
    char State;
    int ArrivalTime;      // 到达时间
    int ServeTime;        // 服务时间
    int StartTime;        // 开始时间
    int EndTime;          // 结束时间
    float TurnaroundTime; // 周转时间
    float TakePowerTime;  // 带权周转时间
    struct PCB *next;
} PCB;

PCB Queue[MAX] = {0};
int time; // 计时器
int n;    // 进程数量

void CreateProcessQueue()
{
    printf("Number of processes created:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // 进程初始化
        Queue[i].State = 'f';
        Queue[i].StartTime = 0;
        Queue[i].EndTime = 0;
        Queue[i].TakePowerTime = 0;
        Queue[i].TurnaroundTime = 0;
        printf("Process ID  Process name  Arrival Time  Service time\n");
        scanf("%d %s %d %d", &Queue[i].no, &Queue[i].name, &Queue[i].ArrivalTime, &Queue[i].ServeTime);
    }
}

void Run(PCB pcb)
{
    pcb.State = 't';
    pcb.StartTime = time;
    pcb.EndTime = pcb.ServeTime + pcb.StartTime;
    time = pcb.EndTime;
    pcb.TurnaroundTime = pcb.EndTime - pcb.ArrivalTime;
    pcb.TakePowerTime = pcb.TurnaroundTime / pcb.ServeTime;
    printf("Pro_id Pro_name Start_time End_time Turnaround_time Turnaround_time_with_rights\n");
    printf("%d       %s         %d        %d        %.2f \t    %.2f\n", pcb.no, pcb.name, pcb.StartTime, pcb.EndTime, pcb.TurnaroundTime, pcb.TakePowerTime);
}

void sort()
{
    // 按到达时间排序
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if (Queue[i].ArrivalTime > Queue[i + 1].ArrivalTime)
            {
                PCB temp = Queue[i];
                Queue[i] = Queue[i + 1];
                Queue[i + 1] = temp;
            }
        }
    }
}

void SJF()
{
    sort();
    time = Queue[0].ArrivalTime;

    for (int i = 0; i < n; i++)
    {
        if (Queue[i].State = 'f')
        {
            if (i == 0)
            {
                Run(Queue[i]);
            }
            else if (Queue[i].ArrivalTime < time)
            {
                int num = i;
                while (Queue[num].ArrivalTime < time && num < n)
                {
                    num++;
                }
                for (int x = i; x < num; x++)
                {
                    for (int t = i; t < num - x; t++)
                    {
                        if (Queue[t].ServeTime > Queue[t + 1].ServeTime)
                        {
                            PCB temp = Queue[t];
                            Queue[t] = Queue[t + 1];
                            Queue[t + 1] = temp;
                        }
                    }
                }
                Run(Queue[i]);
            }
            else
            {
                Run(Queue[i]);
            }
        }
    }
}

int main()
{
    CreateProcessQueue();
    SJF();

    system("pause");
    return 0;
}