#include<iostream>
#include<set>
#include<algorithm>
using namespace std;		

int main()
{
	int N, C, SG, SB, x;
	cin >> N;
		while (N--)
		{
			multiset<int> A;
			multiset<int> B;
			cin >> C >> SG >> SB;
			for (int i = 0; i < SG; i++)
				cin >> x, A.insert(x);
			for (int i = 0; i < SB; i++)
				cin >> x, B.insert(x);
			while (A.size() && B.size())
			{
				multiset<int> a;
				multiset<int> b;
				int k = min(A.size(), B.size());
				k = min(k, C);
				multiset <int>::iterator ritA;
				multiset <int>::iterator ritB;
				for (int i = 0; i < k; i++)
				{
					ritA = --A.end();
					ritB = --B.end();
					if (*ritA > *ritB)
						a.insert(*ritA - *ritB);
					else if (*ritA < *ritB)
						b.insert(*ritB - *ritA);

					A.erase(ritA);
					B.erase(ritB);
				}
				A.insert(a.begin(), a.end());
				B.insert(b.begin(), b.end());
			}
			if (A.size() > B.size())
			{
				cout << "green wins\n";
				for (auto it = A.rbegin(); it != A.rend(); it++)
					 cout << *it << endl;
			}
			else if (A.size() < B.size())
			{
				cout << "blue wins\n";
				for (auto it = B.rbegin(); it != B.rend(); it++)
					cout << *it << endl;
			}
			else cout << "green and blue died\n";
			if(N) cout << endl;
		}
	system("PAUSE");
	return 0;
}