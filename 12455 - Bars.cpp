#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, p, x;
		set <int> sums, temp;
		sums.insert(0);
		cin >> n >> p;
		for (int i = 0; i < p; i++)
		{
			cin >> x;
			for (auto it = sums.begin(); it!=sums.end();it++)
			{
				temp.insert( *it + x);
			}
			sums.insert(temp.begin(), temp.end());
		}

		auto it = sums.find(n);
		if (it == sums.end())cout << "NO\n";
		else cout << "YES\n";
	}
	system("PAUSE");
	return 0;
}