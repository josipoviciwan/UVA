#include<queue>
#include<iostream>
#include<tuple>
#include <string>
#include<algorithm>
#include<climits>
using namespace std;

int LeftFrst, RightFrst;

int main()
{
	int n, c, m,  t;
	cin >> c;
	while (c--)
	{
		int time = 0, x, carry = 0;
		queue<int>  L, R, l, r;
		cin >> n >> t >> m;
		vector< string > V(m);
		string s;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> s;
			V[i] = s;
			if (s == "left")
				L.push(x);
			else R.push(x);
		}

		LeftFrst = (L.empty()) ? INT_MAX : L.front();
		RightFrst = (R.empty()) ? INT_MAX : R.front();
		bool onleft = true;
		bool goright = (LeftFrst <= RightFrst && onleft) ? true : false;
		int arrival  = min(RightFrst, LeftFrst);
		time = arrival;
		while (L.size() || R.size())
		{
			if (onleft)
			{
				while (L.size() && carry < n && L.front() <= time)
				{
					l.push(time + t);
					L.pop();
					carry++;
				}
				time += t;
				onleft = false;
			}
			else
			{
				while (R.size() && carry < n && R.front() <= time)
				{
					r.push(time + t);
					R.pop();
					carry++;
				}
				time += t;
				onleft = true;
			}
			LeftFrst = (L.empty()) ? INT_MAX : L.front(); 
			RightFrst = (R.empty()) ? INT_MAX : R.front();
			arrival = min(LeftFrst, RightFrst); //Vrijeme prvog koji je stigo
			bool leftsmaller = (LeftFrst <= RightFrst) ? true : false;
			if (time < arrival && leftsmaller && left)
				time = arrival;
			else if(time < arrival && (!leftsmaller && left || !left&&leftsmaller))
				time = arrival;
			else if (time < arrival && !leftsmaller && !left)
				time = arrival;
			carry = 0;
		}
		for (int i = 0; i < m; i++)
		{
			if (V[i] == "left")
				O << l.front() << endl, l.pop();
			else O << r.front() << endl, r.pop();
		}
		if (c) O << endl;
	}
	system("PAUSE");
	return 0;
}