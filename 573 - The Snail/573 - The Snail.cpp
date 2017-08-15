#include<iostream>
using namespace std;

int main() {
	int H, U, D, F;
	while (cin >> H >> U >> D >> F && H)
	{
		int day = 0, fail = 0;
		float prev = U, climbed = 0, lost = -U*(F/100.0);
		while (0 < climbed < H)
		{
			day++;
			if (prev > 0)climbed += prev;
			prev += lost;
			if (climbed > H) break;
			climbed -= D;
			if (climbed < 0) {
				fail = 1; break;
			}
		}
		if (fail) cout << "failure ";
		else cout << "success ";
		cout << "on day " << day << endl;
	}
	system("PAUSE");
	return 0;
}