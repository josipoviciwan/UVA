#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

class Node {
public:
	int data, parent, rank;
	Node(int a = -1 ) : data(a), parent(a), rank(0){};
};

class DisjointSet {
public:
	map<int, Node> M;

	void makeSet(int a)
	{
		Node node (a);
		M[a] = node;
	}

	int findParent(int a)
	{
		int b = M[a].parent;
		if (a == b) return a;
		M[a].parent  = findParent(b);
		return M[a].parent;
	}

	void unionSet(int a, int b)
	{
		int x = findParent(a);
		int y = findParent(b);
		if (a == b)return;
		int rank1 = M[x].rank;
		int rank2 = M[y].rank;
		if (rank1 > rank2)
			M[y].parent = x;
		else if (rank2 > rank1)
			M[x].parent = y;
		else
		{
			M[x].parent = y;
			M[y].rank *= 2;
		}
	}
};

int main() {
	int N;
	cin >> N;

	while (N--)
	{		
		string s;
		int n, succ = 0, unsucc = 0;
		cin >> n;
		DisjointSet ds;	
		cin.ignore();
		for (int i = 1; i <= n; i++)
			ds.makeSet(i);
		while (getline(cin, s,'\n') && !s.empty())
		{
			istringstream iss(s);
			char c;
			iss >> c;
			int a, b;
			iss >> a >> b;
			if (c == 'c') ds.unionSet(a, b);
			else (ds.findParent(a) == ds.findParent(b)) ? succ++ : unsucc++;
		}
		cout << succ << "," << unsucc << endl;
		if (N) cout << endl;
	}
	
	system("PAUSE");
	return 0;
}