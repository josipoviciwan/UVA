#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

long long int an(vector<int>& A, int n)
{
	int size = A.size();
	long long int ans = 0;
	for (int i = 0; i < size; i++)
	{

		ans  +=  A[i] * pow(n,i);
	}
	return ans;
}

int main() {
	int C;
	cin >> C;
	while (C--)
	{
		int I;
		cin >> I;
		long int d, k;
		vector<int> A(I+1);
		for (int o = 0; o <= I  ; o++)
			cin >> A[o];

		cin >> d >> k;
		int n = 1, sum = 0;
		while (sum < k)
		{
			sum += d*n;
			n++;
		}
		cout << an(A, n -1)<<endl;
	}
	system("PAUSE");
	return 0;
}