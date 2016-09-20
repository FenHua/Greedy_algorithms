/*Kruskal.cpp : �������̨Ӧ�ó������ڵ㡣
Kruskal�㷨����G����С�������Ļ���˼���ǣ����Ƚ�G��n�����㿴��n����
������ͨ��֧�������еı߰�Ȩ��С��������Ȼ��ӵ�һ���߿�ʼ������Ȩ��
����˳��鿴ÿһ���ߣ�����������������2����ͬ����ͨ��֧�����鿴����k��
��(v,w)ʱ������˵�v��w�ֱ��ǵ�ǰ2����ͬ����ͨ��֧T1��T2�еĶ���ʱ������
��(v,w)��T1��T2���ӳ�һ����ͨ��֧��Ȼ������鿴��k+1���ߣ�����˵�v��w��
��ǰ��ͬһ����ͨ��֧�У���ֱ���ٲ鿴��k+1���ߡ��������һֱ���е�ֻʣ��һ����ͨ��֧ʱΪֹ��
*/

#include "stdafx.h"
#include"MinHeap.h"
#include"UnionFind.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

const int N = 10;//ͼ�ı���
const int M = 6;//ͼ�Ķ�����
ifstream fin("C:\\Users\\YAN\\Desktop\\data.txt");//data���ݵ�λ��

template<class Type>class EdgeNode
{
	friend ostream&operator<<(ostream&, EdgeNode<Type>);
	friend int main(void );
public:
	Type weight;
	int u, v;
	operator Type()const
	{
		return weight;
	}
};
template<class Type>bool Kruskal(int n, int e, EdgeNode<Type>E[], EdgeNode<Type>t[])
{
	MinHeap<EdgeNode<Type>>H(e);
	//��ʼ����С��
	for (int i = 1; i <= e; i++)
	{
		H.Insert(E[i]);
	}
	UnionFind U(n);
	int k = 1;
	while (e && (k <(n - 1)))
	{
		EdgeNode<int>x;
		x = H.RemoveMin();
		e--;
		//����u�а�������v����ͨ��֧������
		int a = U.Find(x.u);
		int b = U.Find(x.v);
		if (a != b)
		{
			t[k++] = x;
			U.Union(a, b);
		}
	}
	return (k == (n - 1));
}


int main()
{
	EdgeNode<int>E[N + 1], t[N + 1];//�洢��ͨ��Ȩͼ���бߵ����˶��㣬Ȩ
	cout << "��ͨ��Ȩͼ���Ե����˶��㣬Ȩ�ֱ�Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		fin >> E[i].u >> E[i].weight >> E[i].v;
		cout << "u:" << E[i].u << ",weight:" << E[i].weight << ",v:" << E[i].v;
		cout << endl;
	}
	if (Kruskal(M + 1, N, E, t))
	{
		cout <<" Kruskal�㷨��С������ѡ����Ϊ" << endl;
		for (int i = 1; i < M; i++)
		{
			cout << "u:" << t[i].u << ",weight:" << t[i].weight << ",v:" << t[i].v << endl;
		}
	}
	return 0;
}

