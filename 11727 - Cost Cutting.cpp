#include<iostream>
#include<set>
using namespace std;
int main() {
	int n, cnt = 1;
	cin >> n;
	while (n--) {
		set <int> S;
		int a, b, c;
		cin >> a >> b >> c;
		S.insert(a);
		S.insert(b);
		S.insert(c);
		cout << "Case " << cnt++ << ": " << *(++S.begin()) << endl;

	}

	system("PAUSE");
	return 0;
}