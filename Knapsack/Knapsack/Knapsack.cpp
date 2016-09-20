/*Knapsack.cpp : 定义控制台应用程序的入口点。
背包问题：与0-1背包问题类似，所不同的是在选择物品i装入背包时，可以选择物品i的一部分，而不
一定要全部装入背包，1≤i≤n。这2类问题都具有最优子结构性质，极为相似，但背包问题可以用贪心
算法求解，而0-1背包问题却不能用贪心算法求解。用贪心算法解背包问题的基本步骤是，首先计算每
种物品单位重量的价值Vi/Wi，然后，依贪心选择策略，将尽可能多的单位重量价值最高的物品装入背包。
若将这种物品全部装入背包后，背包内的物品总重量未超过C，则选择单位重量价值次高的
物品并尽可能多地装入背包。依此策略一直地进行下去，直到背包装满为止。
*/

#include "stdafx.h"
#include"iostream"
using namespace std;

const int N = 3;
void Knapsack(int n, float M, float v[], float w[], float x[]);


int main()
{
	float M = 50;//背包所能容纳的重量
	//这里给定的物品按单位价值递减排序
	float w[] = {0,10,20,30};//下标从1开始
	float v[] = {0,60,100,120};
	float x[N + 1];
	cout << "背包所能容纳的重量为：" << M << endl;
	cout << "待装物品的重量和价值分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "[" << i << "]:(" << w[i] << "," << v[i] << ")" << endl;
	}
	Knapsack(N, M, v, w, x);
	cout << "选择装下对的物品比例如下：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "[" << i << "]:" << x[i] << endl;
	}
	return 0;
}

void Knapsack(int n, float M, float v[], float w[], float x[])
{
	//Sort(n,v,w);//这里假定w[],v[]已经按要求排好序
	int i;
	for (i = 1; i <= n; i++)
	{
		x[i] = 0;//初始化数组X[]
	}
	float c = M;
	for (i = 1; i <= n; i++)
	{
		if (w[i] > c)
		{
			break;
		}
		x[i] = 1;
		c -= w[i];//整个装下,x[i]记为1
	}
	//物品i只有部分装下
	if (i <= n)
	{
		x[i] = c / w[i];
	}
}