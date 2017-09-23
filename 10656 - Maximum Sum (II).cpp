#include<iostream>
using namespace std;

int main()
{
	int n, t, space, ans;
	while (cin >> n && n)
	{
		space = ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			if (t == 0) continue;
			if (space) cout << " ";
			cout << t;
			space = 1;
			ans = 1;
		}
		if(!ans) cout << 0;
		cout << endl;
	}
	system("PAUSE");
	return 0;
}