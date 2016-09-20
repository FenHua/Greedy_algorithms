/*GreedySelector.cpp : 定义控制台应用程序的入口点。
求解思路：将活动按照结束时间进行从小到大排序。然后用i代表第i个活动，s[i]代表
第i个活动开始时间，f[i]代表第i个活动的结束时间。按照从小到大排序，挑选出结束
时间尽量早的活动，并且满足后一个活动的起始时间晚于前一个活动的结束时间，全
部找出这些活动就是最大的相容活动子集合。事实上系统一次检查活动i是否与当前已
选择的所有活动相容。若相容活动i加入已选择活动的集合中，否则，不选择活动i，而
继续下一活动与集合A中活动的相容性。若活动i与之相容，则i成为最近加入集合A的活动，并取代活动j的位置。
*/

#include "stdafx.h"
#include"iostream"
using namespace std;

template<class Type>void GreedySelector(int n, Type s[], Type f[], bool A[]);
const int N = 11;


int main()
{
	//下标从1开始,存储活动开始时间  
	int s[] = { 0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
	//下标从1开始,存储活动结束时间  
	int f[] = { 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	bool A[N + 1];
	cout << "各活动的开始时间,结束时间分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "[" << i << "]:" << "(" << s[i] << "," << f[i] << ")" << endl;
	}
	GreedySelector(N, s, f, A);
	cout << "最大相容活动子集为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		if (A[i])
		{
			cout << "[" << i << "]" << "(" << s[i] << "," << f[i] << ")" << endl;
		}
	}
	return 0;
}
template<class Type>void GreedySelector(int n, Type s[], Type f[], bool A[])
{
	A[1] = true;
	int j = 1;//记录最近一次加入A中的活动
	for (int i = 2; i <= n; i++)
	{
		if (s[i] >= f[j])
		{
			A[i] = true;
			j = i;
		}
		else
		{
			A[i] = false;
		}
	}
}

