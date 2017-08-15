#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, n;
	cin >> N;
	while (N--)
	{
		cin >> n;
		vector<int> V(n), B(n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> V[i];
			int cnt = 0;
			for (int j = 0; j < i; j++)
			{
				if (V[j] <= V[i])
					sum++;
			}

		}
		cout << sum << endl;
	}
	system("PAUSE");
	return 0;
}