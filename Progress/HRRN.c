#include <stdio.h>
#include <windows.h>
#define N 10

typedef struct
{
    int hour;
    int min;
} time;
typedef struct hrrf
{
    char hrrf_id[20];
    double hrrf_run;     // 运行时间
    time hrrf_entertime; // 进入时间
    int enter;
    time hrrf_needtime; // 调度时间
    int needtime;
    time hrrf_endtime; // 结束时间
    int endtime;
    int hrrf_longtime;      // 周转时间
    int hrrf_waittime;      // 等待时间
    double hrrf_pjlongtime; // 平均周转时间
    double hrrf_rate;       // 响应比

    struct hrrf *next;
} HRRF;
// 输入作业信息
void hrrfinput(HRRF s[N], int k)
{
    printf("\tPlease enter the No %d job name", k + 1);
    scanf("%s", &s[k].hrrf_id);
    printf("\tPlease enter %s job entry time:", s[k].hrrf_id);
    scanf("%d:%d", &s[k].hrrf_entertime.hour, &s[k].hrrf_entertime.min);
    s[k].enter = s[k].hrrf_entertime.hour * 60 + s[k].hrrf_entertime.min;
    printf("\tPlease enter %s job run time:", s[k].hrrf_id);
    scanf("%lf", &s[k].hrrf_run);
}
// 计算作业的响应比
void rate(HRRF s[N], int k, int m)
{
    double ratenum;
    ratenum = (s[k].hrrf_run + (double)(s[m].endtime - s[k].enter)) / (s[k].hrrf_run);
    s[k].hrrf_rate = ratenum;
    printf("\n\tResponse ratio per calculation:%s---%f\n", s[k].hrrf_id, s[k].hrrf_rate);
}
// 按响应比大小对作业进行排序（降序排序）
void ratesort(HRRF s[N], int k, int m)
{
    int maxratenum;
    HRRF temp;
    int i, j;
    for (i = k; i < m; i++) // 简单选择排序
    {
        maxratenum = i;
        for (j = i + 1; j < m; j++)
            if (s[j].hrrf_rate > s[maxratenum].hrrf_rate)
                maxratenum = j;
        if (maxratenum != i)
        {
            temp = s[i];
            s[i] = s[maxratenum];
            s[maxratenum] = temp;
        }
    }
}
// 打印表单
void print(HRRF s[N], int k)
{
    printf("\t serial number \t job name \t entry time \t dispatch time \t end time \t run time \t wait time \t turnaround time \n");
    int i, j;
    for (i = 0; i < k; i++)
        printf("\t%d\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\t\t%.0f min\t\t%d\t\t%d min\n", i + 1, s[i].hrrf_id, (s[i].enter / 60), (s[i].enter % 60), (s[i].needtime / 60), (s[i].needtime % 60), (s[i].endtime / 60), (s[i].endtime % 60), s[i].hrrf_run, s[i].hrrf_waittime, s[i].hrrf_longtime);
}

// hrrf算法
void HRRF_run(HRRF s[N], int k)
{
    int i, j = k, n;
    double sum;
    HRRF temp;
    // 按到达时间进行排序
    while (j > 1)
    {
        for (i = 0; i < j - 1; i++)
        {
            if (s[i + 1].enter < s[i].enter)
            {
                temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
            }
        }
        j--;
    }
    printf("\n\t--------------------------------------------Initial state------------------------------------------------\n");
    print(s, k);
    j = 0;
    // 执行
    do
    {
        if (j == 0)
        {
            s[j].needtime = s[j].enter;
            s[j].hrrf_waittime = 0;
            s[j].endtime = s[j].enter + s[j].hrrf_waittime + (int)(s[j].hrrf_run);
            s[j].hrrf_longtime = s[j].endtime - s[j].enter;
        }
        else
        {
            s[j].needtime = s[j - 1].endtime;
            s[j].hrrf_waittime = s[j - 1].endtime - s[j].enter;
            s[j].endtime = s[j].needtime + (int)(s[j].hrrf_run);
            s[j].hrrf_longtime = s[j].endtime - s[j].enter;
        }
        j++; // 到了第几个作业
        // 计算响应比
        n = j - 1; // 此次已经执行完的作业序号-1，因为数组从0开始
        for (i = j; i < k; i++)
        {
            rate(s, i, n); // 计算响应比
        }
        ratesort(s, j, k); // 按响应比由大到小排序
        printf("\n\t-----------------------------------------Sort each response by ratio---------------------------------------------\n");
        print(s, k);

    } while (j < k);

    printf("\n\t--------------------------------------------Job scheduling------------------------------------------------\n");
    print(s, k);
    for (i = 0; i < k; i++)
    {
        sum += (double)(s[i].hrrf_longtime);
    }

    printf("\n\tThe average turnaround time is:%.2f\n", sum / k);
}

int main()
{
    HRRF a[N] = {0};
    int i, j;
    printf("Please enter the number of created jobs:");
    scanf("%d", &i);
    for (j = 0; j < i; j++) // 输入作业信息
        hrrfinput(a, j);
    // HRRF算法
    HRRF_run(a, j);

    system("pause");
    return 0;
}