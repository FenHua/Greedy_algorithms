class UnionFind
{
public:
	UnionFind(int);
	~UnionFind();
	int Find(int);
	void Union(int, int);
private:
	int EleNum;
	int*Parents;
	int *Rank;
};
UnionFind::UnionFind(int n)
{
	EleNum = n;
	Parents = new int[EleNum];
	Rank = new int[EleNum];
	for (int i = 0; i < EleNum; i++)
	{
		Parents[i] = -1;
		Rank[i] = 1;
	}
}
UnionFind::~UnionFind()
{
	delete[]Parents;
	delete[]Rank;
}
int UnionFind::Find(int i)
{
	int r = i;
	while (Parents[r] != -1)
		r = Parents[r];
	while (r != i)
	{
		int q = Parents[i];
		Parents[i] = r;
		i = q;
	}
	return r;
}
void UnionFind::Union(int i, int j)
{
	int a = Find(i);
	int b = Find(j);
	if (a == b)
		return;
	if (Rank[a] > Rank[b])
	{
		Parents[b] = a;
		Rank[a] += Rank[b];
	}
	else
	{
		Parents[a] = b;
		Rank[b] += Rank[a];
	}
}