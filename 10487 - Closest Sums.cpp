#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
using namespace std;

int main() {
	int N, K, cnt = 1;
	while (cin >> N && N)
	{
		set<int> S;
		set<int>sums;
		vector <int> num(N);
		int x;
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			num[i] = x;
			for (int j = 0; j < i; j++)
				sums.insert(x + num[j]);
		}

		cout << "Case " << cnt++ << ":\n";

		cin >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x;
			int ans;
			auto it = sums.lower_bound(x); //Nadi dobrog
			if (it == sums.end()) //Nema dobrog, uzmi prvog manjeg
				ans = *(--it);
			else if (it == sums.begin()) //Prvi je najbolji
				ans = *(it);
			else			//Provjeri koje je bolji, nadeni, ili onaj prije njega
			{
				auto it1 = it--;
				ans = (abs(x - *it) < abs(x - *it1)) ? *it : *it1;

			}
			cout << "Closest sum to " << x << " is " << ans << ".\n";
		}
	}
	system("PAUSE");
	return 0;
}