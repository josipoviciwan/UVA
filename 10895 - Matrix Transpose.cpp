#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

bool NoZero(int a) { return a != 0; }

int main() {
	int m, n;
	while (cin >> m >> n)
	{
		set <int> S;
		map<int, int>M;
		vector<vector<int> > A(m,vector<int>(n,0)); //RADI SUPER!!!
		vector<vector<int> > T(n, vector<int>(m, 0));
		for (int i = 0; i < m; i++) 
		{
			int r, x;
			cin >> r;
			for (int j = 0; j < r; j++) // Popamti indexe
			{
				cin >> x;
				S.insert(x);
			}
			for (auto it = S.begin(); it != S.end(); it++) //Ucitaj na korespondnom indexu
			{
				cin >> A[i][*it - 1];
			}
			S.clear(); //Zaboravi indexe
		}
		
		for (int i = 0; i < m; i++)		//Sad transponiraj spremi u T
			for (int j = 0; j < n; j++)
				T[j][i] = A[i][j];

		//ISPIS RJESENJA
		cout << n << " " << m << endl;
		for (int i = 0; i < n; i++) //Pazi n pa m
		{
			for (int j = 0; j < m; j++)
			{
				if (T[i][j] != 0) {
					M[j+1] = T[i][j];
				}
			}
			cout << M.size() ;
			for (auto it = M.begin(); it != M.end(); it++) {
				cout << " "<<(*it).first ;
			}
			cout << endl;
			for (auto it = M.begin(); it != M.end(); it++) {
				if (it == M.begin()) cout << (*it).second;
				else cout  << " " << (*it).second;
			}
			cout << endl;
			M.clear();
		}
	}
	system("PAUSE");
	return 0;
}