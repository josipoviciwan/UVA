#include<iostream>
#include<map>
#include<string>
using namespace std;

class Node {
public:
	string name;
	string parent;
	int rank;
	Node(string s = "") :name(s), parent(s), rank(0) {};
};

class DisjointSet {
public:
	map<string, Node> M;
	void makeSet(string s)
	{
		Node node(s);
		node.rank = 1;
		M[s] = node;
	}
	string findParent(string s)
	{
		string p = M[s].parent;
		if (s == p) return s;
		M[s].parent = findParent(p);
		return M[s].parent;
	}
	void unionSet(string a, string b)
	{
		string p1 = findParent(a);
		string p2 = findParent(b);
		int r1 = M[p1].rank;
		int r2 = M[p2].rank;
		if (p1 == p2)return;
		if (r1 > r2)
		{
			M[p2].parent = p1;
			M[p1].rank += M[p2].rank;
		}
		else 
		{
			M[p1].parent = p2;
			M[p2].rank += M[p1].rank;
		}
	}
};

int main()
{
	int N, n;
	cin >> N;
	while (N--)
	{
		string s, t;
		cin >> n;
		DisjointSet ds;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> t;
			if (! ds.M[s].rank) ds.makeSet(s);
			if (! ds.M[t].rank) ds.makeSet(t);
				ds.unionSet(s, t);
				int  t = ds.M[ds.findParent(s)].rank;
				cout << t << endl;
		}

	}
	system("PAUSE");
	return 0;
}