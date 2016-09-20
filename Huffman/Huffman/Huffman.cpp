/*Huffman.cpp : �������̨Ӧ�ó������ڵ㡣
�������������
�����������������ǰ׺���̰���㷨���ɴ˲����ı��뷽����Ϊ���������롣�乹�첽�����£�
(1)�������㷨���Ե����ϵķ�ʽ�����ʾ����ǰ׺��Ķ�����T��
(2)�㷨��|C|��Ҷ��㿪ʼ��ִ��|C|��1�εġ��ϲ�����������������Ҫ�����T��
(3)��������ַ�����ÿһ�ַ�c��Ƶ����f(c)����fΪ��ֵ�����ȶ���Q����̰��ѡ��ʱ��Ч��ȷ���㷨
��ǰҪ�ϲ���2�þ�����СƵ�ʵ�����һ��2�þ�����СƵ�ʵ����ϲ��󣬲���һ���µ�������Ƶ��Ϊ��
����2������Ƶ��֮�ͣ����������������ȶ���Q������n��1�εĺϲ������ȶ�����ֻʣ��һ��������
��Ҫ�����T��
*/

#include "stdafx.h"
#include"BinaryTree.h"
#include"MinHeap.h"
#include"iostream"
using namespace std;

const int N = 6;
template<class Type>class Huffman;
template<class Type>BinaryTree<int>HuffmanTree(Type f[], int n);
template<class Type>class Huffman
{
	friend BinaryTree<int>HuffmanTree(Type[], int n);
public:
	operator Type() const
	{
		return weight;
	}
	BinaryTree<int>tree;
	Type weight;
};
template<class Type>BinaryTree<int>HuffmanTree(Type f[], int n)
{
	Huffman<Type>*w = new Huffman<Type>[n + 1];//���ɵ��ڵ���
	BinaryTree<int>z, zero;
	for (int i = 1; i <= n; i++)
	{
		z.MakeTree(i,zero,zero);
		w[i].weight = f[i];
		w[i].tree = z;
	}
	//�����ȶ���
	MinHeap<Huffman<Type>>Q(n);
	for (int i = 1; i <= n; i++)
		Q.Insert(w[i]);
	//�����ϲ���СƵ����
	Huffman<Type>x, y;
	for (int i = 1; i < n; i++)
	{
		x = Q.RemoveMin();
		y = Q.RemoveMin();
		z.MakeTree(0,x.tree,y.tree);
		x.weight += y.weight;
		x.tree = z;
		Q.Insert(x);
	}
	x = Q.RemoveMin();
	delete[] w;
	return x.tree;
}

int main()
{
	char c[] = { '0', 'a', 'b', 'c', 'd', 'e', 'f' };
	int f[] = { 0, 45, 13, 12, 16, 9, 5 };//�±��1��ʼ 
	BinaryTree<int>t = HuffmanTree(f, N);
	cout << "���ַ����ֵĶ�ӦƵ�ʷֱ�Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << c[i] << ":" << f[i] << " ";
	}
	cout << endl;
	cout << "���ɶ�������ǰ��������Ϊ��" << endl;
	t.Pre_Order();
	cout << endl;
	cout << "���ɶ�����������������Ϊ��" << endl;
	t.In_Order();
	cout << endl;
	t.DestroyTree();
	return 0;
}

