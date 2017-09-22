#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	int n, t, frst = 1;
	while (cin >> n && n)
	{
		if (!frst) cout << endl, frst = 0;
		vector<int> v(n);
		map<int, int> M;
		int m = 1;
		vector<int> used(n, 0);
		for (int i = 0; i < n; i++)
			cin >> v[i], M[v[i]]++, m = max(m, M[v[i]]);
		sort(v.begin(), v.end());

		cout << m << endl;
		
		for (int i = 0; i < n; i++)
		{
			if (used[i]) continue;
			for (int j = i; j < n; j+= m)
			{
				if (j == i) cout << v[j];
				else if (used[j])continue;
				else cout << " " << v[j];
				used[j] = 1;
			}
			cout << endl;
		}
	}
	system("PAUSE");
	return 0;
}