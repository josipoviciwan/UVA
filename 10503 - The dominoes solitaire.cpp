#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
ofstream o("Text.txt");
bool ans ;
int s1, s2, e1, e2;

void solve(vector<vector<int>> &in, int curr, int currsize, int endsize)
{
	if (currsize ==  endsize)
	{
		if ( curr == e1 ) ans = true;
		return;
	}

	for (int i = 0; i < 7; i++)
	{
		if (in[curr][i])
		{
			vector<vector<int>> temp(in);
			in[curr][i] --;
			if (curr != i) in[i][curr]--;
			solve(in, i, 1 + currsize, endsize);
			in[curr][i] ++;
			if (curr != i) in[i][curr]++;
		}
	}
	return;
}

int main()
{
	int m, n;
	while (cin >> n && n && cin >> m)
	{
		int k, l;
		vector<vector<int>> V(7, vector<int>(7, 0));
		cin >> s1 >> s2 >> e1 >> e2;
		for (int i = 0; i < m; i++)
		{
			cin >> k >> l;
			V[k][l] ++;
			if (k != l)V[l][k]++;
		}
		ans = false;
		solve(V, s2, 0, n);
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	system("PAUSE");
	return 0;
}