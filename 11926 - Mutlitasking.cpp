#include<iostream>
#include<tuple>
#include<set>
#include<fstream>
using namespace std;

ofstream A("Text1.txt");

int main() {
	int a, b;
	while (cin >> a >> b && a || b) {
		int A[1000001] = {};
		int x, y, z;
		for (int i = 0; i < a; i++) {
			cin >> x >> y;
			for (int j = x+1; j < y; j++) A[j]++;
		}
		for (int i = 0; i < b; i++) {
			cin >> x >> y >> z;
			for (int j = x+1; j<=100000 && j < y; j++) A[j]++;
		}

		bool overlap = false;

		for (int i = 0; i < 1000001; i++) if (A[i] > 1)overlap = true;
		if (overlap) A << "CONFLICT\n";
		else A << "NO CONFLICT\n";
	}
	system("pause");
	return 0;
}
