#include<iostream>
#include<map>
#include<string>
#include<set>
#include<iomanip>
using namespace std;

int main() {
	int  N;
	string s;
	cin >> N;
	cin.ignore();
	cin.ignore();
	while (N--) {
		int cnt = 0;
		map <string, float> M;
		set<string> S;
		while (getline(cin,s) && s!="") {
			M[s]++;
			S.insert(s);
			cnt++;
		}
		for (auto it = S.begin(); it != S.end(); it++)
		cout << *it << " " << setprecision(4) << fixed << 100* M[*it] /cnt << endl;
		if (N > 0) cout << endl;
	}
	system("PAUSE");
	return 0;
}