/*Prim.cpp : 定义控制台应用程序的入口点。
Prim算法
设G=(V,E)是连通带权图，V={1,2,…,n}。构造G的最小生成树的Prim算法的基本思想是：首先置S={1}，然
后，只要S是V的真子集，就作如下的贪心选择：选取满足条件iÎS，jÎV-S，且c[i][j]最小的边，将顶点j添加到
S中。这个过程一直进行到S=V时为止。在这个过程中选取到的所有边恰好构成G的一棵最小生成树。
*/
#include "stdafx.h"
#include<fstream>
#include<string>
#include"iostream"
using namespace std;

#define inf 9999;
const int N = 6;
ifstream fin("C:\\Users\\YAN\\Desktop\\data.txt ");//文件存放位置
template<class Type>void Prim(int n, Type c[][N + 1]);

int main()
{
	int c[N + 1][N + 1];
	cout << "连通带权图的矩阵为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			fin >> c[i][j];
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Prim 算法最小生成树选边次序如下：" << endl;
	Prim(N, c);
	return 0;
}

template<class Type>void Prim(int n, Type c[][N + 1])
{
	Type lowcost[N + 1];//记录c[j][colosest]的最小权值
	int closest[N+1];//V-S中点j在s中的最邻接顶点
	bool s[N + 1];
	s[1] = true;
	//初始化s[i],lowcost[i],closest[i]
	for (int i = 2; i <= n; i++)
	{
		lowcost[i] = c[1][i];
		closest[i] = 1;
		s[i] = false;
	}
	for (int i = 1; i < n; i++)
	{
		Type min = inf;
		int j = 1;
		for (int k = 2; k <= n; k++)
		{
			if ((lowcost[k] < min) && (!s[k]))
			{
				min = lowcost[k];
				j = k;//找出V-S中使lowcost最小的顶点j
			}
		}
		cout << j << ' ' << closest[j] << endl;
		s[j] = true;//将j添加到s中
		for (int k = 2; k <= n; k++)
		{
			//将j添加到S中后，修改closest和lowcost的值
			if ((c[j][k] < lowcost[k]) && (!s[k]))
			{
				lowcost[k] = c[j][k];
				closest[k] = j;
			}
		}
	}
}
