/*Greedy_Dijkstra.cpp : 定义控制台应用程序的入口点。
给定带权有向图G =(V,E)，其中每条边的权是非负实数。另外，还给定V中的一个顶点，称为源。现在要计算从源到所有其他各顶点的最短路长度。
这里路的长度是指路上各边权之和。这个问题通常称为单源最短路径问题。
*/

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int N = 5;
const int M = 1000;
ifstream fin("C:\\Users\\YAN\\Desktop\\data.txt");//文件所在位置
template<class Type>void Dijkstra(int n, int v, Type dist[], int prev[], Type c[][N + 1]);
void Traceback(int v, int i, int prev[]);//输出最短路径，v为源点，i为终点

int main()
{
	int v = 1;//源点为1
	int dist[N + 1], prev[N + 1], c[N + 1][N + 1];
	cout << "有向图的矩阵为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			fin >> c[i][j];
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	Dijkstra(N, v, dist, prev, c);
	for (int i = 1; i < 6; i++)
		cout << prev[i];
	for (int i = 2; i <= N; i++)
	{
		cout << "源1到点" << i << "的最短路劲长度为：" << dist[i] << ",其路径为：";
		Traceback(1, i, prev);
		cout << endl;
	}
	return 0;
}

template<class Type>void Dijkstra(int n, int v, Type dist[], int prev[], Type c[][N + 1])
{
	bool s[N + 1];
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];//dist[i]表示当前从源点到顶点i的最短特殊路径长度
		s[i] = false;
		if (dist[i] ==M)
		{
			prev[i] = 0;//记录从源到顶点i的最短路径i的前一个顶点
		}
		else
		{
			prev[i] = v;
		}
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n; i++)
	{
		int temp = M;
		int u = v;//上一顶点
		//取出V-S中具有最短路径长度的顶点U
		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;
		//根据贪心更新dist值
		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (c[u][j] < M))
			{
				Type newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}
void Traceback(int v, int i, int prev[])//输出最短路径，v源点，i终点
{
	if (v == i)
	{
		cout << i;
		return;
	}
	Traceback(v, prev[i], prev);
	cout << "->" << i;
}