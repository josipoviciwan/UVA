#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

int main()

{
	int N, K;
	while (cin >> N)
	{
		cin >> K;
		int time = 0, awake = 3;
		map <char, bool> M;
		map<char, set<char>> conections;
		char a, b, c, d, e;
		cin >> a >> b >> c;
		M[a] = M[b] = M[c] = 1;

		for (int i = 0; i < K; i++)
		{
			cin >> d >> e;
			conections[d].insert(e);
			conections[e].insert(d);
			M[e];
			M[d];
		}
		map <char, bool> temp;
		while (awake < N && temp != M)
		{
			temp = M;

			for (auto it = temp.begin(); it != temp.end(); it++)
			{
				//	cout << "Frst-> " << (*it).first << " Scnd-> " << (*it).second << endl;
				if (!(*it).second)
				{
					int cnt = 0;
					char sign = (*it).first;

					for (auto it = conections[sign].begin(); it != conections[sign].end(); it++)
					{
						cnt += temp[*it];
					}
					if (cnt > 2) M[sign] = 1, awake++;
				}
			}
			time++;


		}
		if (awake == N)
			cout << "WAKE UP IN, " << time << ", YEARS" << endl;
		else cout << "THIS BRAIN NEVER WAKES UP" << endl;

	}
	system("PAUSE");
	return 0;
}