/*Loading.cpp : 定义控制台应用程序的入口点。
问题描述：有一批集装箱要装上一艘载重量为c的轮船。其中集装箱i的重量为Wi。最优装载问题要求确定在装载体积不受限制的
情况下，将尽可能多的集装箱装上轮船。
最优子结构性质：设(x1,x2,……xn)是最优装载问题的满足贪心选择性质的最优解，则易知，x1=1,(x2,x3,……xn)是轮船载重量为
c-w1，待装船集装箱为{2,3，……n}时相应最优装载问题的最优解。因此，最优装载问题具有最优子结构性质。
求解过程：最优装载问题可用贪心算法求解。采用重量最轻者先装的贪心选择策略，可产生最优装载问题的最优解。
*/

#include "stdafx.h"
#include"iostream"
using namespace std;

const int N = 4;
template<class Type>void Swap(Type &x, Type&y);
template<class Type>void Loading(int x[], Type w[], Type c, int n);
template<class Type>void SelectSort(Type w[], int *t, int n);

int main()
{
	float c = 70;
	float w[] = { 0, 20, 10, 26, 15 };//下标从1开始
	int x[N + 1];
	cout << "轮船载重为：" << c << endl;
	cout << "待装载物品的重量分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	Loading(x, w, c, N);
	cout << "贪心选择的结果为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
	return 0;
}

template<class Type>void Loading(int x[], Type w[], Type c, int n)
{
	int *t = new  int[n + 1];//存储排完序后w[]的原始索引
	SelectSort(w, t, n);
	for (int i = 1; i <= n; i++)
	{
		x[i] = 0;//初始化数组x[]
	}
	for (int i = 1; (i <= n) && (w[t[i]] <= c); i++)
	{
		x[t[i]] = 1;
		c -= w[t[i]];
	}
}
template<class Type>void SelectSort(Type w[], int*t, int n)
{
	Type tempArray[N + 1];
	memcpy(tempArray, w, (n + 1)*sizeof(Type));//将w拷贝到临时数组tempArray中
	int min;
	for (int i = 1; i <= n; i++)
	{
		t[i] = i;
	}
	for (int i = 1; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (tempArray[min]>tempArray[j])
			{
				min = j;
			}
		}
		Swap(tempArray[i], tempArray[min]);
		Swap(t[i], t[min]);
	}
}
template<class Type>void Swap(Type&x, Type&y)
{
	Type temp = x;
	x = y;
	y = temp;
}