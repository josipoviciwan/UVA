#include<iostream>
#include<set>
#include<utility>
#include<climits>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
int main()
{
	int t, n, x, y, p;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector< vector<int> > city(5, vector<int>(5,0));
		vector<int>ans(5);
		int total = INT_MAX;
		for (int i = 0; i < n; i++)
			cin >> x >> y >> p, city[x][y] = p;
		for(int i= 0; i <25;i++)
			for(int j = i+1; j < 25;j++)
				for(int k = j+1; k < 25;k++)
					for(int s = k+1; s<25;s++)
						for (int l = s + 1; l < 25; l++) {

							int sum = 0;

							for(int a = 0; a<5;a++)
								for (int b = 0; b < 5; b++)
								{
									int d1 = abs(a - i / 5) + abs(b - i % 5);
									int d2 = abs(a - j / 5) + abs(b - j % 5);
									int d3 = abs(a - k / 5) + abs(b - k % 5);
									int d4 = abs(a - s / 5) + abs(b - s % 5);
									int d5 = abs(a - l / 5) + abs(b - l % 5);
									int min1 = min(d1, d2);
									min1 = min(min1, d3);
									min1 = min(min1, d4);
									min1 = min(min1, d5);
									sum += min1*city[a][b];
								}
							if (sum < total) {
								total = sum;
								ans[0] = i;
								ans[1] = j;
								ans[2] = k;
								ans[3] = s;
								ans[4] = l;
							}

						}
		for (int i = 0; i < 5; i++)
		{
			if (!i)
				cout << ans[i];
			else cout << " " << ans[i];
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}