/*MultiMachineSchedule.cpp : 定义控制台应用程序的入口点。
多机调度问题：
贪心算法求解思路
采用最长处理时间作业优先的贪心策略:
当n≤m时, 只要将机器i的[0, ti]时间区间分配给作业i即可。
当n>m时, 将n个作业依其所需的处理时间从大到小排序,然后依次将作业分配给空闲的处理机。
*/

#include "stdafx.h"
#include"MinHeap.h"
#include"iostream"
#include<fstream>
using namespace std;

const int N = 7;//作业的个数
const int M = 3;//机器台数
ifstream fin("C:\\Users\\YAN\\Desktop\\data.txt");
class JobNode
{
public:
	int ID, time;
	operator int() const
	{
		return time;
	}
};
class MachineNode
{
public:
	int ID, avail;
	operator int()const
	{
		return avail;
	}
};
template<class Type>void Greedy(Type a[], int n,int m);
template<class Type>void SelectSort(Type a[], int n);

int main()
{
	JobNode a[N + 1];//各作业所需的处理时间
	cout << "各作业所需的处理时间:" << endl;
	for (int i = 1; i <= N; i++)
	{
		fin >> a[i].ID >> a[i].time;
		cout << "ID:" << a[i].ID << ",time:" << a[i].time << endl;
	}
	Greedy(a, N, M);
	return 0;
}

template<class Type>void Greedy(Type a[], int n, int m)
{
	if (n <= m)
	{//机器数量多余作业数量
		cout << "直接为每一个作业分配一台机器" << endl;
		return;
	}
	SelectSort(a, n);//排序，从打到小
	MinHeap<MachineNode>H(m);
	MachineNode x;
	for (int i = 1; i <= m; i++)
	{
		x.avail = 0;
		x.ID = i;
		H.Insert(x);
	}
	for (int i = 1; i <= n; i++)
	{
		x = H.RemoveMin();
		cout << "将机器" << x.ID << "从" << x.avail << "到" << (x.avail + a[i].time)
			<< "的时间段分配给作业" << a[i].ID << endl;
		x.avail += a[i].time;
		H.Insert(x);//根据新的avail值将x插入heap中的适当位置
	}
}
template<class Type>void SelectSort(Type a[], int n)
{
	Type temp;
	int max;
	for (int i = 1; i < n; i++)
	{
		max = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[max] < a[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}
}

