#include<iostream>
#include<math.h>
#include<set>
#include<utility>
#include<iomanip>
#include<cstdio>
using namespace std;

int main() {
	int n;
	while (cin >> n)
	{
		set <pair<long long int, long long int>> S;
		for (int i = 1+n; i <= n+n; i++)
		{
			double  b = (1.0*n*i)/(i-n);
			if (floor(b)==ceil(b)) {
				S.insert(make_pair(b, i));
			}

		}
		cout << S.size()<<endl;

		for (auto it = S.rbegin(); it != S.rend(); it++)
		{
			cout << "1/" << n << " = 1/" << (*it).first << " + 1/" << (*it).second << endl;
		}
	}
	system("PAUSE");
	return 0;
}