#include<iostream>
#include<string>
#include<iomanip>
#include<map>
using namespace std;

int main() {
	int N, M,K;
	cin >> N;
	while (N--) {
		map <char, double> P;
		double sum = 0;
		 char a;
		string b;
		cin >> K;
		while (K--) {
			cin >> a >> b;
			P[a] = stof(b) / 100;
		}
		b.resize(10000);
		cin >> M;
		cin.ignore();

		while (M--) {
			getline(cin, b);
			for (int i = 0; i < b.size(); i++)
				if (P.find(b[i]) != P.end())
					sum += P[b[i]];
		}
	
		cout << setprecision(2) << fixed << sum << "$"<<endl;
	}
	system("PAUSE");
	return 0;
}