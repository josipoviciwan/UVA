#include<iostream>
#include<set>
using namespace std;

int main()
{
	int n, r, d;
	while (cin >> n >> d >> r && (n || r || d)) 
	{
		int ans = 0, t;
		multiset<int>morning;
		multiset<int>evening;
		for (int i = 0; i < n; i++)
			cin >> t, morning.insert(t);

		for (int i = 0; i < n; i++)
			cin >> t, evening.insert(t);
		for (int i = 0; i < n; i++)
		{
			auto it1 = morning.begin();
			auto it2 = --evening.end();
			int a = *it1, b = *it2;
			if (a + b > d) ans += (a + b) - d;
			morning.erase(it1);
			evening.erase(it2);
		}
		cout << ans*r << endl;
	}
	system("PAUSE");
	return 0;
}
