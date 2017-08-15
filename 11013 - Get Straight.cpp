#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int value(char A) {
	switch (A) {
	case'A':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case'8':return 8;
	case '9':return 9;
	case 'T':return 10;
	case 'J':return 11;
	case 'Q':return 12;
	case 'K':return 13;
	}

}

int main() {
	string s;

	while ( getline(cin,s,'\n') && s != "#" ) {
		int A[5];
	for (int i = 0; i < 5; i++) {
		A[i] = value(s[3 * i]);
		}
	sort(A, A + 5);
	cout << endl;
	for (int i = 0; i < 5; i++) cout << A[i] << "   ";
	cout << endl;
	}

	system("PAUSE");
	return 0;
}