#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int T;
	string S;
	cin >> T;
	while (T--)
	{
		int sum = 0;
		cin >> S;
		vector <int> V(80, 0);
		for (int i = 0; i <(int)S.size(); i++) {
			if (S[i] == 'O') {
				V[i] = 1;
				if (i) V[i] += V[i - 1];
				sum += V[i];
			}
		}
		cout << sum << endl;
		V.clear();
	}
	system("pause");
	return 0;
}