#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

int main()
{
	int n;
	bool first = true;
	while (cin >> n && n)
	{
		if (!first) cout << endl;
		vector<string> V(n);
		for (int i = 0; i < n; i++)
			cin >> V[i];
		for (long int i = 1 << n; i > 0; i--)
		{
			long int t = i;
			bitset <13> bs(t);
			if (bs.count() == 6) {
				string ans = "";
				for (int j = n - 1; j > -1; j--)
				{
					if (t % 2)
					{
						if (ans.size() == 0) ans = V[j];
						else
							ans = V[j] + " " + ans;

					}
					t /= 2;
				}
				 cout << ans << endl;
			}
		}
		first = false;
	}
	system("PAUSE");
	return 0;
}