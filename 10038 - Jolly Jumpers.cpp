#include<iostream>
#include<set>
#include<math.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		bool C = true ;
		set <int> S;
		int A[3000];
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < n - 1; i++) {
			int dif = abs(A[i] - A[i + 1]);
			S.insert(dif);
			if (dif < 1 || dif >= n) C = false;

		}

		if (n == (S.size()+1) && C ) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	system("PAUSE");
	return 0;
}