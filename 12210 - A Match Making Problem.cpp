#include<set>
#include<iostream>
using namespace std;

int main()
{
	int m, n, t, cnt = 1;
	while (cin >> m >> n && m && n)
	{
		multiset<int> s;
		for (int i = 0; i < m; i++)
			cin >> t, s.insert(t);
		for (int i = 0; i < n; i++)
			cin >> t;
		cout << "Case " << cnt++ << ": ";
		if (m <= n) cout << 0 << endl;
		else cout << m - n << " " << *s.begin() << endl;
	}

	system("PAUSE");
	return 0;
}