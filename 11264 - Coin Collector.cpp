#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, T;
	cin >> T;
	while (T--)
	{
		long long int sum = 0;
		cin >> n;
		int ans = 1;
		vector<long int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 0; i < n - 1; i++)
			if (sum + v[i] < v[i + 1])sum += v[i], ans++;
		cout << ans << endl;
	}
	system("PAUSE");
	return 0;
}