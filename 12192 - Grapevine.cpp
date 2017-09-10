#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, M, C, L, U;
	while (cin >> N >> M && N && M)
	{
		vector<vector<int>> V(N, vector<int>(M));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> V[i][j];
		cin >> C;
		while (C--)
		{
			int sol = 0;
			cin >> L >> U;
			for (int i = 0; i < N; i++)
			{
				auto it = lower_bound(V[i].begin(), V[i].end(), L); //9 iteracija najvise
				int j = it - V[i].begin();
				for (int l = sol; l < N; l++)
				{
					if (l + j >= M || i + l >= N || V[i + l][j + l] > U) break; 
					sol = max(sol, l + 1); //Zaboravio increment, da nevalja linija 26 bi breakala
				}
			}
			cout << sol << "\n";
		}
		cout << "-\n";
	}
	system("PAUSE");
	return 0;
}