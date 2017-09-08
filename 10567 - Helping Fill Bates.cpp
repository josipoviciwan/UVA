#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s, t;
	char c;
	getline(cin, s);
	vector< vector<int> > indexes(256);
	for (int i = 0; i < (int)s.size(); i++)
		indexes[s[i] - '0'].push_back(i);
	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		getline(cin, t);
		int frst = -1, last = -1 , ans = 1, curr = -1;
		for (int i = 0; i < (int)t.size(); i++)
		{
			auto it = upper_bound(indexes[t[i] - '0'].begin(), indexes[t[i] - '0'].end(), curr);
			if (it == indexes[t[i] - '0'].end()) { ans = 0; break; }
			curr = *it;
			if (frst == -1) frst = curr;
			last = curr;
		}
		if (ans) cout << "Matched " << frst << " " << last << endl;
		else cout << "Not matched" << endl;
	}

	system("PAUSE");
	return 0;
}