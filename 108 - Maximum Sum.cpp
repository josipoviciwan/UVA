#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, ans;
	while (cin >> N) {
		ans = -127 * 10000;
		vector< vector<int> > A(101, vector<int>(101));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> A[i][j];
				if (i) A[i][j] += A[i - 1][j];
				if (j) A[i][j] += A[i][j - 1];
				if (i&&j)  A[i][j] -= A[i - 1][j - 1];
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int i1 = i; i1 < N; i1++)
					for (int j1 = j; j1 < N; j1++)
					{
						int t = A[i1][j1];
						if (i) t -= A[i - 1][j1];
						if (j)t -= A[i1][j - 1];
						if (i && j)t += A[i - 1][j - 1];
						ans = max(t, ans);
					}
		cout << ans << endl;
	}
	return 0;
}