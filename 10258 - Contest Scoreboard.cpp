#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
#include<sstream>
#include<cstring> 

using namespace std;


class PLAYER {
public:
	int num, solved, penalty;
	int P[9];
	bool S[9] = {0,0,0,0,0,0,0,0,0};
	PLAYER(int a = 0, int b = 0, int c = 0) :num(a), solved(b), penalty(c) { memset(P, 0, sizeof P); }
	bool operator < (PLAYER a)
	{
		if (solved < a.solved)
			return  true;
		else if (solved == a.solved && penalty > a.penalty)
			return true;
		else if (solved == a.solved && penalty == a.penalty && num >a.num)
			return true;
		return false;
	}

	friend ostream &operator<<(ostream& stream,  PLAYER &a) {
		stream << a.num << " " << a.solved << " " << a.penalty<< endl;
		return stream;
	}
};

int main() {
	int  C;
	string s;
	cin >> C;
	cin.ignore();
	cin.ignore();
	while (C--)
	{
		vector<PLAYER> v(100);
		while (getline(cin, s, '\n') && s != "")
		{
			int a, b, c;
			char L;
			istringstream iss(s);
			iss >> a >> b >> c >> L;
			if (v[a - 1].num == 0) v[a - 1] = PLAYER(a);

			if (L == 'C' && !(v[a - 1].S[b - 1]))

			{
				v[a - 1].penalty += c + v[a - 1].P[b - 1];
				v[a - 1].solved++;
				v[a - 1].S[b - 1] = 1;
			}
			if (L == 'I' && !v[a-1].S[b-1]) v[a - 1].P[b-1] += 20;

		}
		sort(v.rbegin(), v.rend());
		for (int i = 0; i <(int)v.size(); i++)
			if (v[i].num) cout << v[i];
		if (C) cout << endl;
	}
	system("PAUSE");
	return 0;
}