#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//WORKS FINE, BUT BIG INT CLASS REQUIRED...

int main()
{
	do
	{
		long long int ans = INT_MIN;
		vector<long int> v(100);
		vector<vector< long long int>> prod(100, vector<long long int>(2, 1));
		for (int i = 0; i < 100; i++)
		{
			cin >> v[i];
			if (v[i] == -999999) break;
			prod[i][0] = v[i];
			ans = (ans > v[i]) ? ans : v[i];
			for (int j = 0; j < i; j++)
			{
				long int temp = v[i] * prod[j][1];
				if (temp * prod[j][0] > prod[j][0]) prod[j][0] *= temp, prod[j][1] = 1;
				else prod[j][1] *= v[i];
				ans = (ans > prod[j][0]) ? ans : prod[j][0];
			}
		}
		cout << ans << "\n";

	} while (!cin.eof());
	system("PAUSE");
	return 0;
}