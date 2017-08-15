#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k, t, m ;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		m = -1;
		cin >> k;
		while (k--)
			cin >> t, m = max(t, m);
		cout << "Case " << i << ": " << m << endl;

	}
	system("PAUSE");

	return 0;
}