#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
	int N, n, curr, last, ans, a, b, c;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{

		cin >> n;
		last = 0;
		ans = 0;
		vector<int> V(n);

		for (int j = 0; j < n; j++)
		{
			cin >> curr;
			int t = curr - last;
			V[j] = t;
			last = curr;
			if (ans == t) ans++;
			else ans = max(ans, t);
		}
		a = ans - 1, b = ans, c = ans + 1;
		for (int j = 0; j < n; j++)
		{
			if (V[j] > a) a = -1;
			else if (V[j] == a)a--;

			if (V[j] > b) b = -1;
			else if (V[j] == b)b--;

			if (V[j] > c) c = -1;
			else if (V[j] == c)c--;
		}
		if (a + 1) ans--;
		else if (b + 1);
		else if (c + 1) ans++;
		cout << "Case " << i << ": " << ans << endl;
	}
	system("PAUSE");
	return 0;
}