/*MultiMachineSchedule.cpp : �������̨Ӧ�ó������ڵ㡣
����������⣺
̰���㷨���˼·
���������ʱ����ҵ���ȵ�̰�Ĳ���:
��n��mʱ, ֻҪ������i��[0, ti]ʱ������������ҵi���ɡ�
��n>mʱ, ��n����ҵ��������Ĵ���ʱ��Ӵ�С����,Ȼ�����ν���ҵ��������еĴ������
*/

#include "stdafx.h"
#include"MinHeap.h"
#include"iostream"
#include<fstream>
using namespace std;

const int N = 7;//��ҵ�ĸ���
const int M = 3;//����̨��
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
	JobNode a[N + 1];//����ҵ����Ĵ���ʱ��
	cout << "����ҵ����Ĵ���ʱ��:" << endl;
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
	{//��������������ҵ����
		cout << "ֱ��Ϊÿһ����ҵ����һ̨����" << endl;
		return;
	}
	SelectSort(a, n);//���򣬴Ӵ�С
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
		cout << "������" << x.ID << "��" << x.avail << "��" << (x.avail + a[i].time)
			<< "��ʱ��η������ҵ" << a[i].ID << endl;
		x.avail += a[i].time;
		H.Insert(x);//�����µ�availֵ��x����heap�е��ʵ�λ��
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

