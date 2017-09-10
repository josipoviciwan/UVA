#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<fstream>
#include<iomanip>
using namespace std;

int p, q, r, s, t, u;

float f(float x)
{
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{

	vector<float> V(100001);
	for (int i = 0; i <= 10000; i++)
		V[i] = i / (float)10000.0;
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		float min = INT_MAX, sol = -1;
		for (int i = 0; i <= 10000; i++)
		{
			float ans = abs(f(V[i]));
			if (ans < min)
			{
				min = ans;
				sol = V[i];
			}

		}
		if (min < 0.005)
			cout << setprecision(4) << fixed<<sol << "\n";
		else cout << "No solution\n";
	}
	
	system("PAUSE");
	return 0;
}