#include<iostream>
#include <string>
using namespace std;

string in, out;

void f(string i, string o, string s, string P, int n) {

	if (n == 2 * in.size()) {
		if (o == out)
			cout << P << "\n";
		return;
	}

	if (i.size())
		f(i.substr(1, i.size() - 1), o, s + i[0], P + (n ? " i" : "i"), n + 1);

	if (s.size() && s[s.size() - 1] == out[o.size()])
		f(i, o + s[s.size() - 1], s.substr(0, s.size() - 1), P + " o", n + 1);
}

int main() {
	while (cin >> in >> out) {
		cout << "[\n";
		f(in, "", "", "", 0);
		cout << "]\n";
	}
	system("Pause");
	return 0;
}