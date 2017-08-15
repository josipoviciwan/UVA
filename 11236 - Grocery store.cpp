
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	for (int s = 1; 4 * s <= 2000; s++) {
		for (int i = s; s + 3 * i <= 2000; i++) {
			for (int j = i; s + i + 2 * j <= 2000; j++) {

				long long int  sum = (s + j + i), prod = (s*i*j);
				if (prod <= 1000000) continue;
				if ((1000000 * sum % (prod - 1000000)) == 0) {
					long long int d = 1000000 * sum / (prod - 1000000);

					if (j <= d && sum + d <= 2000)
						cout << setprecision(2) << fixed << s / 100.0 << " " << i / 100.0 << " " << j / 100.0 << " " << d / 100.0 << endl;

				}
			}
		}
	}

	system("PAUSE");
	return 0;
}