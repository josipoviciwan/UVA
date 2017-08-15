#include<iostream>
#include<string>
#include<vector>
using namespace std;

class car {
public:
	int min;
	int max;
	string s;
	car(string a="", int b=0, int c=0) :min(b), max(c), s(a) {};
};

int main() {
	int n, N, Q, price;
	cin >> N;
	while (N--)
	{
		cin >> n;
		string s, temp;
		int a, b;
		vector <car> V(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s >> a >> b;
			car C(s, a, b);
			V[i] = C;
		}
		cin >> Q;
		while (Q--)
		{
			bool found = false;
			cin >> price;
			cin.ignore();
			for (int i = 0; i < n; i++)
			{
				if (V[i].min <= price && V[i].max >= price) {
					if (found) {
						s = "UNDETERMINED";
						break;
					}
					else s = V[i].s, found = true;
				}
			}
			if (!found) s = "UNDETERMINED" ;
			cout << s <<endl;
		}
		if (N)cout << endl;
	}
	system("PAUSE");
	return 0;
}