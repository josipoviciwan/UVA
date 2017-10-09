#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	long long int N, A, B, C, ans;
	cin >> N;
	vector<vector<vector<long long int>>> V(20, vector<vector<long long int>>(20, vector<long long int>(20)));

	while (N--)
	{
		ans = INT_MIN;
		cin >> A >> B >> C;
		for (int i = 0; i < A; i++)
		{
			for (int j = 0; j < B; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> V[i][j][k];
					if (i) V[i][j][k] += V[i - 1][j][k];
					if (j) V[i][j][k] += V[i][j - 1][k];
					if (k) V[i][j][k] += V[i][j][k - 1];
					if (i && j) V[i][j][k] -= V[i - 1][j - 1][k];
					if (i && k)V[i][j][k] -= V[i - 1][j][k - 1];
					if (j && k)V[i][j][k] -= V[i][j - 1][k - 1];
					if (i && j && k) V[i][j][k] += V[i - 1][j - 1][k - 1];
				}
			}
		}

		for (int i = 0; i < A; i++)
		{
			for (int j = 0; j < B; j++)
			{
				for (int k = 0; k < C; k++)
				{
					for (int i1 = i; i1 < A; i1++)
					{
						for (int j1 =  j; j1 < B; j1++)
						{
							for (int k1 = k; k1 < C; k1++)
							{
								long long int t = V[i1][j1][k1];
								if (i) t -= V[i - 1][j1][k1];
								if (j) t -= V[i1][j - 1][k1];
								if (k) t -= V[i1][j1][k - 1];
								if (i && j) t+= V[i - 1][j - 1][k1];
								if (i && k)t += V[i - 1][j1][k - 1];
								if (j && k)t += V[i1][j - 1][k - 1];
								if (i && j && k)t -= V[i - 1][j - 1][k - 1];
								ans = max(t, ans);
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
		if (N) cout << endl;
	}
	system("PAUSE");
	return 0;
}