#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
using namespace std;

int main() {

	int f, r;
	float x;
	while (cin >> f && f && cin >> r)
	{
		vector<float> F(f);
		vector<float>R(r);
		set<float> ratios, spread;
		for (int i = 0; i < f; i++)
			cin >> F[i];
		for (int i = 0; i < r; i++)
		{
			cin >> R[i];
			for (int j = 0; j < f; j++)
			{
				ratios.insert(R[i] / F[j]);
			}
		}
		for (auto it = ratios.begin(); it != --ratios.end(); it++) {
			it++;
			spread.insert(*(it) / *(--it));
		}
		cout << setprecision(2)<<fixed<<*spread.rbegin() << endl;
	}

	system("PAUSE");
	return 0;
}