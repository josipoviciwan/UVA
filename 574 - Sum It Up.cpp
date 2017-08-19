#include<set>
#include<iostream>
#include<bitset>
#include<functional>
#include<vector>
using namespace std;


int main()
{
	int t, n;
	while (cin >> t >> n && n)
	{
		cout << "Sums of " << t << ":" << endl;
		bool found = false;
		set < multiset<int, greater<int>> > SM;
		vector<int> array(n), empty;
		for (int i = 0; i < n; i++)
			cin >> array[i];
		for (int j = (1 << n) - 1; j > 0; j--)
		{
			bitset<12> bs(j);
			int sum = 0;
			multiset<int, greater<int> > temp;
			for (int i = 0; i < n; i++)
				if (bs[i]) sum += array[i], temp.insert(array[i]);
			if (sum == t)
			{
				SM.insert(temp);
			}
		}
		set<int, greater<int>>::iterator rit;
		set<multiset<int, greater<int>>>::reverse_iterator RIT;
		for (RIT = SM.rbegin(); RIT != SM.rend(); RIT++)
		{
			for (rit = (*RIT).begin(); rit != (*RIT).end(); rit++)
			{
				if (rit == (*RIT).begin()) cout << *rit;
				else cout << "+" << *rit;

			}
			cout << endl;
		}
		if (SM.empty())cout << "NONE\n";
	}
	system("PAUSE");
	return 0;
}