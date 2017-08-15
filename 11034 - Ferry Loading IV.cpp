#include<queue>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n, l, m, x;
	string s;
	cin >> n;
	while (n--) 
	{
		int ferry = 0, ans = 0;
		queue<int> L, R;
		cin >> l >> m;
		l = l * 100;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> s;
			if (s == "left") L.push(x);
			else R.push(x);
		}

		while (L.size() || R.size())
		{
			while (L.size())
			{
				if (ferry + L.front() <= l)
				{
					ferry += L.front();
					L.pop();
				}
				else break;
			}
			ans++;
			ferry = 0;

			if (L.empty() && R.empty()) break;

			while (R.size())
			{

				if (ferry + R.front() <= l)
				{
					ferry += R.front();
					R.pop();
				}
				else break;
			}
			ans++;
			ferry = 0;
		}
		cout << ans << endl;
	}

	system("PAUSE");
	return 0;
}