#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

double molar(char X) {
	switch (X) {
	case'C':return 12.010;
	case 'H':return 1.008;
	case 'O':return 16.000;
	case 'N':return 14.010;
	}
}

int main() {
	int C;
	cin >> C;
	string s;
	while (C--) {
		cin >> s;
		double sum = 0;

		for (int i = 0 ; i < s.size(); i++) {
			if (isalpha(s[i])) {
				int temp = 0, j = i;
				while (j < s.size() - 1 && !isalpha(s[j + 1])) {
					temp++;
					j++;
				}
				temp = (j > i) ? stoi(s.substr(i + 1, j)) : 1;
				sum += temp*molar(s[i]);
			}
		}
		cout << setprecision(3) <<fixed << sum << endl; //setpr - 3 mjesta, fixed - tocno tri decimale!!!
	}
	system("pause");
	return 0;
}