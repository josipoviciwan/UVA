#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
	int N, T, ans;
	cin >> T;
	while (T--)
	{
		ans = -100 * 75 * 75;
		cin >> N;
		vector< vector<int> > A(2 * 75, vector<int>(2 * 75));
		vector< vector<int> > B(2 * 75, vector<int>(2 * 75));
		for (int i = 0; i < N; i++)  //Unesi II. kvadrant
			for (int j = 0; j < N; j++)
			{
				cin >> A[i][j];
				B[i][j] = A[i][j];
				if (i) A[i][j] += A[i - 1][j];
				if (j) A[i][j] += A[i][j - 1];
				if (i&&j)  A[i][j] -= A[i - 1][j - 1];
			}

		for (int i = 0; i < N; i++)	//Unesi I. kvadrant
			for (int j = N; j < 2 * N; j++)
			{
				A[i][j] = B[i][j - N];
				if (i) A[i][j] += A[i - 1][j];
				if (j) A[i][j] += A[i][j - 1];
				if (i&&j)  A[i][j] -= A[i - 1][j - 1];
			}
		for (int i = N; i < 2 * N; i++) //Unesi III. kvadrant
			for (int j = 0; j < N; j++)
			{
				A[i][j] = B[i - N][j];
				if (i) A[i][j] += A[i - 1][j];
				if (j) A[i][j] += A[i][j - 1];
				if (i&&j)  A[i][j] -= A[i - 1][j - 1];
			}
		for (int i = N; i < 2 * N; i++) //Unesi IV. kvadrant
			for (int j = N; j < 2 * N; j++)
			{
				A[i][j] = B[i - N][j - N];
				if (i) A[i][j] += A[i - 1][j];
				if (j) A[i][j] += A[i][j - 1];
				if (i&&j)  A[i][j] -= A[i - 1][j - 1];
			}
		for (int i = 0; i < 2 * N; i++) //RQS
			for (int j = 0; j < 2 * N; j++)
				for (int i1 = i; i1 < 2 * N && i1 - i < N; i1++)
					for (int j1 = j; j1 < 2 * N && j1 - j < N; j1++)
					{
						int t = A[i1][j1];
						if (i) t -= A[i - 1][j1];
						if (j)t -= A[i1][j - 1];
						if (i && j)t += A[i - 1][j - 1];
						ans = max(t, ans);
					}
		cout << ans << endl;
	}
	system("PAUSE");
	return 0;
}

