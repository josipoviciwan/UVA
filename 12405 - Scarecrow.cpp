#include<iostream>
using namespace std;

int main()
{
	int T;
	char c;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int ans = 0, t, curr = 0;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			cin >> c;
			if (c == '.')
			{
				if (j == 0) ans++, curr = 2;
				else if (curr < j) curr = j + 2, ans++;
			}
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	system("PAUSE");
	return 0;
}