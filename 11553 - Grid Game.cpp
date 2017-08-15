#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<map>
#include<climits>
#include<fstream>
using namespace std;

ofstream o("Text.txt");

int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		vector<int>cols(n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];
			cols[i] = i;
		}
		int ans = INT_MAX;
		
		do{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += grid[j][cols[j]];
			}
			ans = min(ans, sum);
		} while (next_permutation(cols.begin(), cols.end()));

		cout << ans << endl;
	}

	system("PAUSE");
	return 0;
}