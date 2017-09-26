#include<iostream>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
using namespace std;

int main()
{
	unsigned  int N, L, U;
	while(cin >> N >> L >> U)
	{
		
		bitset<33> bs (N);
		unsigned  int  ans = 0;
		unsigned  int m = (int)log2(U);
		for (int i = m; i >= 0; i--)
		{
			if (!bs[i] && ans + (1 << i) <= U) ans += (1 << i);
			else if ( ans + (1 << i )- 1 < L ) ans += (1 << i);
		}
		cout << ans << endl;
	}
	
	system("PAUSE");
	return 0;
}