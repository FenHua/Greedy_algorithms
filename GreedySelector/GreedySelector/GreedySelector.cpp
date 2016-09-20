/*GreedySelector.cpp : �������̨Ӧ�ó������ڵ㡣
���˼·��������ս���ʱ����д�С��������Ȼ����i�����i�����s[i]����
��i�����ʼʱ�䣬f[i]�����i����Ľ���ʱ�䡣���մ�С����������ѡ������
ʱ�価����Ļ�����������һ�������ʼʱ������ǰһ����Ľ���ʱ�䣬ȫ
���ҳ���Щ������������ݻ�Ӽ��ϡ���ʵ��ϵͳһ�μ��i�Ƿ��뵱ǰ��
ѡ������л���ݡ������ݻi������ѡ���ļ����У����򣬲�ѡ��i����
������һ��뼯��A�л�������ԡ����i��֮���ݣ���i��Ϊ������뼯��A�Ļ����ȡ���j��λ�á�
*/

#include "stdafx.h"
#include"iostream"
using namespace std;

template<class Type>void GreedySelector(int n, Type s[], Type f[], bool A[]);
const int N = 11;


int main()
{
	//�±��1��ʼ,�洢���ʼʱ��  
	int s[] = { 0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
	//�±��1��ʼ,�洢�����ʱ��  
	int f[] = { 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	bool A[N + 1];
	cout << "����Ŀ�ʼʱ��,����ʱ��ֱ�Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "[" << i << "]:" << "(" << s[i] << "," << f[i] << ")" << endl;
	}
	GreedySelector(N, s, f, A);
	cout << "������ݻ�Ӽ�Ϊ��" << endl;
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
	int j = 1;//��¼���һ�μ���A�еĻ
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

