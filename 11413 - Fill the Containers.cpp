#include<iostream>
#include<vector>

using namespace std;

bool f( vector<int>& v, int n, int m)
{
	long int cnt = 1,  volume = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > n)return false;
		if (volume + v[i] <= n) volume += v[i];
		else volume = v[i], cnt++;
	}
	if (cnt > m) return false;
	return true;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v(n);
		long int high = 1;
		for (int i = 0; i < n; i++)
			cin >> v[i], high+=v[i];
		long int low = 1, mid, ans;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (f(v, mid, m))
			{
				ans = mid;
				high = mid - 1;
			}
			else low = mid +1;
		}
		cout << ans << endl;
	}

	system("PAUSE");
	return 0;
}