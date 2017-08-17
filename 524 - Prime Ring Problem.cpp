#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
#include<fstream>
using namespace std;

ofstream o("Text1.txt");

vector<bool>primes(32); // 16+15 = 31 za svaki slucaj 32
set<vector<int>> S;

bool is_prime(int a)
{
	bool prime = true;
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0) {
			prime = false; continue;
		}
	return prime;
}

void solve(vector<int> make, int n)
{
	if (make.empty()) {
		make.push_back(1),  solve(make, n);
	}
	if (make.size() == n )
	{
		if (!primes[make[n - 1] + make[0]])return;
		S.insert(make);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		vector<int>temp(make);
		if ( find(make.begin(),make.end(),i)==make.end() && primes[make[make.size() - 1] + i ])
		{
			temp.push_back(i);
			solve(temp,  n);

		}

	}
	return;
}

int main()
{
	int n, cnt = 1;

	for (int i = 0; i < 32; i++)
		primes[i] = is_prime(i);

	while (cin >> n)
	{
		vector <int > v(0);
		if (cnt > 1)cout << endl;
		cout << "Case " << cnt++ << ":" << endl;
		if (n % 2 == 0 || n ==1)solve(v, n);
		for (auto it : S) {
			for (auto it1 : it)
				if (it1 == 1)
					cout << 1;
				else cout << " " << it1;
				cout << "\n";
		}

		S.clear();
	}
	system("PAUSE");
	return 0;
}