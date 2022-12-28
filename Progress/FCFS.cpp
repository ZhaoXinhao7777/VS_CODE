#include <iostream>
using namespace std;

#define n 20
typedef struct
{
    int id;      // 进程名
    int atime;   // 进程到达时间
    int runtime; // 进程运行时间
} fcs;
int main()
{
    int amount, i, j, diao, huan;
    fcs f[n];
    cout << "Please enter the number of processes:" << endl;
    cin >> amount;
    for (i = 0; i < amount; i++)
    {
        cout << "Please enter the process name, process arrival time, process running time::" << endl;
        cin >> f[i].id;
        cin >> f[i].atime;
        cin >> f[i].runtime;
    }
    for (i = 0; i < amount; i++) // 按进程到达时间的先后排序
    {                            // 如果两个进程同时到达，按在屏幕先输入的先运行 
        for(j=0;j<amount-i-1;j++)
        {
            if (f[j].atime > f[j + 1].atime)
            {
                diao = f[j].atime;
                f[j].atime = f[j + 1].atime;
                f[j + 1].atime = diao;
                huan = f[j].id;
                f[j].id = f[j + 1].id;
                f[j + 1].id = huan;
            }
        }
    }
    for (i = 0; i < amount; i++)
    {
        cout << "process:"<< " " << f[i].id << " "<< "from" << " " << f[i].atime << "begin work"<< " "
             << ","<< "at"<< " " << f[i].atime + f[i].runtime << " "<< "end before." << endl;
        f[i + 1].atime = f[i].atime + f[i].runtime;
    }

    system("pause");
    return 0;
}