#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int M, N, x;
	while (cin >> M >> N&& M || N)
	{
		int ans = 0;
		set <int> A;
		set <int> B;
		for (int i = 0; i < M; i++)
			cin >> x, A.insert(x);

		for (int i = 0; i < M; i++)
			cin >> x, B.insert(x);
		for (auto it = A.begin(); it != A.end(); it++)
			if (B.find(*it) != B.end())
				ans++;
		cout << ans << endl;

	}

	system("PAUSE");
	return 0;
}