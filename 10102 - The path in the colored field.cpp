#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

int main() {

	int N;
	char x;
	while (cin >> N )
	{
		set <pair<int, int>> O;
		set<pair<int, int>> T;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> x;
				if (x == '1')O.insert(make_pair(i, j));
				if (x == '3')T.insert(make_pair(i, j));
			}

		}
		int MAX = -1;
		for (auto o : O)
		{
			int MIN = N*N;
			for (auto t : T)
			{
				int a = abs(o.first - t.first);
				int b = abs(o.second - t.second);
				MIN = min(MIN, a + b);
			}
			MAX = max(MAX, MIN);
		}
		cout << MAX << endl;
	}
	system("PAUSE");
	return 0;
}