#include<iostream>
#include<set>
#include<map>
using namespace std;

int main() {
	int N;
	while (cin >> N && N) {
		map< set <int> ,int> M;
		for (int i = 0; i < N; i++) {
			int A[5];
			for (int j = 0; j < 5; j++)
				cin >> A[j];
			set <int>X (A, A + 5);
			M [X]++;
		}
		int m = 0;
		int cnt = 0;
		bool unique = true;
		for (map < set<int>, int> ::iterator it = M.begin(); it != M.end(); it++) {
			if ((*it).second > m)
			{
				unique = true;
				m = (*it).second;
			}
			else if ((*it).second == m)
				unique = false;
		}
		for (map < set<int>, int> ::iterator it = M.begin(); it != M.end(); it++)
			if ((*it).second == m)
				cnt+=m;
		
		if(unique) cout << m << "\n";
		else cout << cnt << "\n";
	}
	system("PAUSE");
	return 0;
}