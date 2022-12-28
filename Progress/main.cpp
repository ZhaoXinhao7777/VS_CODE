#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;

class resource {//资源类
public:
	resource() {//设置默认值
		Max = 0;
		Allocation = 0;
		Need = 0;
	}
	int Max;
	int Allocation;
	int Need;
};

class process {//进程类
public:
	process() {//设置默认值
		isyfp = false;
	}
	vector<resource> res_vec;//资源数组
	bool isyfp;//是否已预分配
};

class System {//系统类
public:
	System();//默认构造函数
	bool issafe();//安全性算法
	void print_System();//输出系统当前状态
	void banker();//银行家算法
	bool is_finish();
	bool is_workDneed(vector<int>work, int i);
	bool is_continue(vector<int>);
private:
	vector<process> pro_vec;//进程数组
	vector<int> res_sum;//系统含有的资源总数目
	vector<int> Available;
};

System::System()
{
	int pro_num, res_num;
	cout << "请输入系统中的进程个数: ";
	cin >> pro_num;
	cout << endl;
	while (pro_num < 0) {
		cout << "数据输入有误！ 请重新输入: ";
		cin >> pro_num;
		cout << endl;
	}
	cout << "请输入系统中的资源种类数: ";
	cin >> res_num;
	cout << endl;
	while (res_num < 0) {
		cout << "数据输入有误！ 请重新输入: ";
		cin >> res_num;
		cout << endl;
	}
	for (int i = 0; i < res_num; i++) {
		cout << "请输入系统中" << char('A' + i) << "资源总数: ";
		int m; cin >> m;
		cout << endl;
		while (m < 0) {
			cout << "数据输入有误！ 请重新输入: ";
			cin >> m;
			cout << endl;
		}
		res_sum.push_back(m);
		Available.push_back(m);
	}
	system("cls");
	for (int i = 0; i < pro_num; i++) {
		process pro;
		for (int j = 0; j < res_num; j++) {
			cout << "请输入第" << i << "个进程" << char('A' + j) << "资源需求总数(Max)和分配数目(Allocation): ";
			resource res;
			cin >> res.Max >> res.Allocation;
			cout << endl;
			while (res.Max < 0 || res.Allocation < 0) {
				cout << "数据输入有误！ 请重新输入: ";
				cin >> res.Max >> res.Allocation;
				cout << endl;
			}
			while (res.Allocation > Available[j]) {
				cout << "系统资源不足分配！ 请重新输入分配数目: ";
				cin >> res.Allocation;
				cout << endl;
			}
			res.Need = res.Max - res.Allocation;
			pro.res_vec.push_back(res);
			Available[j] = Available[j] - res.Allocation;
		}
		pro_vec.push_back(pro);
	}
}

bool System::issafe()
{
	cout << "系统当前状态:\n";
	print_System();
	cout << "--------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < pro_vec.size(); i++)
		pro_vec[i].isyfp = false;
	vector<int>work;
	for (int i = 0; i < Available.size(); i++)
		work.push_back(Available[i]);
	//初始化
	int t = res_sum.size();
	cout << '\t';
	cout << setw(t * 6) << "进程" << setw(t * 6) << "Work" << setw(t * 6) << "Need" << setw(t * 6) << "Allocation" << setw(t * 6) << "work+Allocation";
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------\n";
	//5 3 10 5 7 7 0 5 1 3 0 3 2 2 0 2 0 9 3 0 0 2 2 2 2 2 1 2 1 4 0 3 0 3 2

	//0 2 2 2
	//1 3 3 3
	//1 1 1 1
	vector<int>vec;
	while (is_continue(work) == true) {
		for (int i = 0; i < pro_vec.size(); i++) {
			if (pro_vec[i].isyfp == false && is_workDneed(work, i) == true) {
				vec.push_back(i);
				pro_vec[i].isyfp = true;
				cout << "\tprocess" << i << '\t';
				for (int k = 0; k < work.size(); k++)
					cout << setw(t * 2) << work[k];
				cout << "|";
				for (int k = 0; k < work.size(); k++)
					cout << setw(t * 2) << pro_vec[i].res_vec[k].Need;
				cout << "|";
				for (int k = 0; k < work.size(); k++)
					cout << setw(t * 2) << pro_vec[i].res_vec[k].Allocation;
				cout << "|";
				for (int k = 0; k < work.size(); k++)
					work[k] += pro_vec[i].res_vec[k].Allocation;
				for (int k = 0; k < work.size(); k++)
					cout << setw(t * 2) << work[k];
				cout << endl;
				break;
			}//if
		}//for
	}//while
	cout << "--------------------------------------------------------------------------------------------\n";
	if (is_finish())
	{
		cout << "系统安全!\n" << endl;
		cout << "安全序列为：";
		int j = 0;
		for (; j < vec.size() - 1; j++)
			cout << "process" << vec[j] << "---->";
		cout << "process" << vec[j] << endl;
		return true;
	}
	else {
		cout << "系统不安全!,会造成死锁,下列进程所需资源无法满足\n" << endl;
		for (int j = 0; j < pro_vec.size(); j++) {
			if (pro_vec[j].isyfp == false) {
				cout << "process" << j << "  ";
			}
		}return false;
	}
}

void System::print_System()
{
	cout << "   Available:\t";
	for (int i = 0; i < Available.size(); i++)
		cout << char('A' + i) << " :" << Available[i] << '\t';
	cout << endl;
	cout << left;
	int t = res_sum.size();
	cout << '\t';
	cout << setw(t * 6) << "进程" << setw(t * 6) << "Max" << setw(t * 6) << "Allocation" << setw(t * 6) << "Need";
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < pro_vec.size(); i++) {
		cout << "\tprocess" << i << '\t';
		for (int j = 0; j < pro_vec[i].res_vec.size(); j++)
			cout << setw(t * 2) << pro_vec[i].res_vec[j].Max;
		cout << "|";
		for (int j = 0; j < pro_vec[i].res_vec.size(); j++)
			cout << setw(t * 2) << pro_vec[i].res_vec[j].Allocation;
		cout << "|";
		for (int j = 0; j < pro_vec[i].res_vec.size(); j++)
			cout << setw(t * 2) << pro_vec[i].res_vec[j].Need;
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------------------\n";
}

void System::banker()
{
	vector<int> request;
	if (!issafe())return;
	cout << "请输入要提出新请求的进程序号：\n";
	int n; cin >> n;
	for (int i = 0; i < res_sum.size(); i++) {
		cout << "请输入对资源" << char('A' + i) << "的请求数量： ";
		int m; cin >> m;
		cout << endl;
		while (m < 0) {
			cout << "数据输入有误！ 请重新输入: ";
			cin >> m;
			cout << endl;
		}
		if (m > pro_vec[n].res_vec[i].Need) {
			cout << "Request请求非法！----请求的资源数量大于所需数量(Need)\n";
			return;
		}
		request.push_back(m);
	}
	for (int i = 0; i < res_sum.size(); i++) {
		if (request[i] > Available[i]) {
			cout << "Request>Available----没有足够资源分配，进程必须等待！\n";
			return;
		}
	}
	for (int i = 0; i < res_sum.size(); i++) {
		Available[i] -= request[i];
		pro_vec[n].res_vec[i].Allocation += request[i];
		pro_vec[n].res_vec[i].Need -= request[i];
	}
	if (issafe()) {
		cout << "分配成功！\n";
	}
	else {
		cout << "分配失败！\n";
		for (int i = 0; i < res_sum.size(); i++) {
			Available[i] += request[i];
			pro_vec[n].res_vec[i].Allocation -= request[i];
			pro_vec[n].res_vec[i].Need += request[i];
		}
	}
	//回收
	vector<vector<process>::iterator>v;
	for (vector<process>::iterator it = pro_vec.begin(); it != pro_vec.end(); it++) {
		bool judge = false;
		for (int j = 0; j < res_sum.size(); j++) {
			if (it->res_vec[j].Need != 0)
				judge = true;
		}//need全为0，judge为false
		if (judge == false) {
			for (int k = 0; k < res_sum.size(); k++) {
				Available[k] += it->res_vec[k].Allocation;
			}
			v.push_back(it);
		}
	}
	for (int j = 0; j < v.size(); j++) {
		pro_vec.erase(v[j]);
	}
	return;
}

bool System::is_finish()
{
	for (int i = 0; i < pro_vec.size(); i++)
		if (pro_vec[i].isyfp == false)
			return false;
	return true;
}

bool System::is_workDneed(vector<int> work, int i)
{
	for (int j = 0; j < pro_vec[i].res_vec.size(); j++) {
		if (work[j] < pro_vec[i].res_vec[j].Need)
			return false;
	}
	return true;
}

bool System::is_continue(vector<int>work)
{
	for (int i = 0; i < pro_vec.size(); i++)
		if (pro_vec[i].isyfp == false && is_workDneed(work, i))
			return true;
	return false;
}

void menu() {
	cout << "\t\t|----------------------------------------|\n";
	cout << "\t\t|------------1.执行安全性算法------------|\n";
	cout << "\t\t|------------2.输出系统当前状态----------|\n";
	cout << "\t\t|------------3.进程提出新的请求----------|\n";
	cout << "\t\t|------------4.退出系统------------------|\n";
	cout << "\t\t|----------------------------------------|\n";
	cout << " \t\t请输入执行的功能: ";
}

int main() {
	System sys;
	int func = -1;
	while (func != 4) {
		system("cls");
		menu();
		cin >> func;
		cout << endl;
		switch (func)
		{
		case 1:
			sys.issafe();//执行安全性算法
			break;
		case 2:
			sys.print_System();//输出系统当前状态
			break;
		case 3:
			sys.banker();//进程提出新的请求
			break;
		default:
			break;
		}
		system("pause");
	}
	return 0;
}
