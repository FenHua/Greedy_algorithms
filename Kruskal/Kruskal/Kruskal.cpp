/*Kruskal.cpp : 定义控制台应用程序的入口点。
Kruskal算法构造G的最小生成树的基本思想是，首先将G的n个顶点看成n个孤
立的连通分支。将所有的边按权从小到大排序。然后从第一条边开始，依边权递
增的顺序查看每一条边，并按下述方法连接2个不同的连通分支：当查看到第k条
边(v,w)时，如果端点v和w分别是当前2个不同的连通分支T1和T2中的顶点时，就用
边(v,w)将T1和T2连接成一个连通分支，然后继续查看第k+1条边；如果端点v和w在
当前的同一个连通分支中，就直接再查看第k+1条边。这个过程一直进行到只剩下一个连通分支时为止。
*/

#include "stdafx.h"
#include"MinHeap.h"
#include"UnionFind.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

const int N = 10;//图的边数
const int M = 6;//图的定点数
ifstream fin("C:\\Users\\YAN\\Desktop\\data.txt");//data数据的位置

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
	//初始化最小堆
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
		//返回u中包含顶点v的连通分支的名字
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
	EdgeNode<int>E[N + 1], t[N + 1];//存储连通带权图所有边的两端顶点，权
	cout << "连通带权图所以的两端顶点，权分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		fin >> E[i].u >> E[i].weight >> E[i].v;
		cout << "u:" << E[i].u << ",weight:" << E[i].weight << ",v:" << E[i].v;
		cout << endl;
	}
	if (Kruskal(M + 1, N, E, t))
	{
		cout <<" Kruskal算法最小生成树选择结果为" << endl;
		for (int i = 1; i < M; i++)
		{
			cout << "u:" << t[i].u << ",weight:" << t[i].weight << ",v:" << t[i].v << endl;
		}
	}
	return 0;
}

