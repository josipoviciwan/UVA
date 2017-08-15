#include<iostream>
#include<map>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;
ofstream O("Text.txt");


int main()
{
	int N, S;
	cin >> N;
	while (N--) {
		cin >> S;
		map <long int, int> M;
		int x, cnt = 0, last, sol = 0, interval = 0;
		for (int i = 1; i <= S; i++)
		{
			cin >> x;
			last = M[x];
			if (last)
			{
				interval = max(last, interval);
				cnt = i - interval - 1;
			}
			M[x] = i;
			cnt++;
			sol = max(sol, cnt);

		}
		cout << sol << "\n";
	}

	system("PAUSE");
	return 0;
}

