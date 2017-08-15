#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (a == b) cout << '=';
		if (a < b)cout << '<';
		if (a > b)cout << '>';
		cout << endl;
	}

	system("PAUSE");
	return 0;
}