#include<iostream>
#include<set>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

int main()
{
	int n, t, money, temp;
	while (cin >> n)
	{
		multiset<int> s;
		int frst = -1, last = -1, diff = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			s.insert(t);
		}
		cin >> money;
		multiset<int>::iterator it = s.begin();
		while(s.size())
		{
			temp = *it;
			s.erase(it);
			multiset<int> ::iterator scnd = s.find(money-temp);
			if (scnd != s.end())
			{
				int temp1 = *scnd;
				if (abs(temp - temp1) < diff)
					frst = temp, last = temp1, diff = abs(temp - temp1);
				s.erase(scnd);

			}
			it = s.begin();
		}
		cout << "Peter should buy books whose prices are " << frst << " and " << last << '.'<<endl<<endl;
	}
	system("PAUSE");
	return 0;
}