#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int m, n;
	while (cin >> n >> m && m&&n)
	{
		vector<int> heads(n);
		multiset <int> knights;
		int ans = 0, t, sol = 1;
		for (int i = 0; i < n; i++)
			cin >> heads[i];
		for (int i = 0; i < m; i++)
			cin >> t, knights.insert(t);
		for (int i = 0; i < n; i++)
		{
			auto it = knights.lower_bound(heads[i]);
			if (it == knights.end())
			{
				sol = 0;
				break;
			}
			else ans += *it, knights.erase(it);
		}
		if (sol) cout << ans << endl;
		else cout << "Loowater is doomed!" << endl;

	}
	system("PAUSE");
	return 0;
}