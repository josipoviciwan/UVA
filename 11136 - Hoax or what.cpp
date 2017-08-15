#include<iostream>
#include<set>
using namespace std;

int main() {
	int n;
	while (cin >> n && n )
	{
		multiset <long long int> S;
		int  k ;
		long long int x, ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			while (k--) 
			{
				cin >> x;
				S.insert(x);
			}
			if (S.size() > 1 )
			{
				ans += (*(--S.end()) - *S.begin());
				S.erase(--S.end());
				S.erase(S.begin());
			}
		}
		cout << ans << "\n";
		S.clear();
	}
	system("PAUSE");
	return 0;
}