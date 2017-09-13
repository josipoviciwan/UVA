#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, n;
	while (cin >> N && N)
	{
		int ans = 0, sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> n;
			sum += n;
			if (sum < 0)sum = 0;
			ans = max(ans, sum);

		}
		if (ans) cout << "The maximum winning streak is " << ans << ".\n";
		else cout << "Losing streak.\n";
	}
	system("PAUSE");
	return  0;
}