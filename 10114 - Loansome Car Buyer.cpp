#include<iostream>
#include<map>
#include<fstream>
using namespace std;

ofstream o("Text.txt");
int main() {
	int month, n, t;
	double value, paying, percent;
	while (cin >> month && month > 0 && cin >> paying >> value >> n)
	{
		map<int, float> M;
		int ans = 0;
		double car = value+paying;
		while (n--)
		{
			cin >> t >> percent;
			M[t] = percent;
		}
		percent = M[0];
		car *= (1 - percent);
		paying = value / month;
		while (car <= value && ans < month && value)
		{
			ans++;
			if (M[ans])percent = M[ans];
			car *= (1.0 - percent);
			value -= paying;
		}
		cout<< ans ;
		if (ans == 1)cout << " month\n";
		else cout << " months\n";
	}

	system("PAUSE");
	return 0;
}