#include<iostream>
#include<set>
using namespace std;

int main()
{
	int N;
	long int x;
	while (cin >> N && N)
	{
		multiset<long int> S;
		long int cost = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			S.insert(x);
		}
		while (S.size() > 1)
		{
			int a = *S.begin();
			S.erase(S.begin());
			int b = *(S.begin());
			S.erase(S.begin());
			cost += a + b;
			S.insert(a + b);
		}
		cout << cost << endl;
	}

	system("PAUSE");
	return 0;
}