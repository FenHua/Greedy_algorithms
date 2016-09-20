/*Huffman.cpp : 定义控制台应用程序的入口点。
构造哈弗曼编码
哈夫曼提出构造最优前缀码的贪心算法，由此产生的编码方案称为哈夫曼编码。其构造步骤如下：
(1)哈夫曼算法以自底向上的方式构造表示最优前缀码的二叉树T。
(2)算法以|C|个叶结点开始，执行|C|－1次的“合并”运算后产生最终所要求的树T。
(3)假设编码字符集中每一字符c的频率是f(c)。以f为键值的优先队列Q用在贪心选择时有效地确定算法
当前要合并的2棵具有最小频率的树。一旦2棵具有最小频率的树合并后，产生一棵新的树，其频率为合
并的2棵树的频率之和，并将新树插入优先队列Q。经过n－1次的合并后，优先队列中只剩下一棵树，即
所要求的树T。
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
	Huffman<Type>*w = new Huffman<Type>[n + 1];//生成单节点树
	BinaryTree<int>z, zero;
	for (int i = 1; i <= n; i++)
	{
		z.MakeTree(i,zero,zero);
		w[i].weight = f[i];
		w[i].tree = z;
	}
	//建优先队列
	MinHeap<Huffman<Type>>Q(n);
	for (int i = 1; i <= n; i++)
		Q.Insert(w[i]);
	//反复合并最小频率树
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
	int f[] = { 0, 45, 13, 12, 16, 9, 5 };//下标从1开始 
	BinaryTree<int>t = HuffmanTree(f, N);
	cout << "各字符出现的对应频率分别为：" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << c[i] << ":" << f[i] << " ";
	}
	cout << endl;
	cout << "生成二叉树的前序遍历结果为：" << endl;
	t.Pre_Order();
	cout << endl;
	cout << "生成二叉树的中序遍历结果为：" << endl;
	t.In_Order();
	cout << endl;
	t.DestroyTree();
	return 0;
}

