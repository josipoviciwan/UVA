#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

ofstream o("Text.txt");

class FenwickTree {
private: vector<int> ft; 
public:
	FenwickTree(int n) { ft.assign(n + 1, 0); }

	int rsq(int b) 
	{
		int sum = 0;
		for (; b; b -= (b & -b))
			sum += ft[b];
		return sum;
	}

	int rsq(int a, int b) { 
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
	
	void adjust(int k, int v) {
		for (; k < (int)ft.size(); k += (k & -k)) ft[k] += v;
	}
};



int main()
{
	int N, K, a, b,x;
	char C;
	while (cin >> N >> K)
	{
		vector<int> array(N);
		FenwickTree zeros(N);
		FenwickTree negatives(N);
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			array[i] = x;
			if (x == 0)
				zeros.adjust(i+1, 1);
			if (x < 0)
				negatives.adjust(i+1, 1);
		}
		for (int i = 0; i < K; i++)
		{
			cin >> C >> a >> b;

			if (C == 'C')
			{
				if (array[a-1] == 0 && b != 0)
				{
					zeros.adjust(a, -1);
					if (b < 0)
						negatives.adjust(a, 1);
					
				}
				else if(array[a-1]!=0 && b == 0)
				{
					zeros.adjust(a, 1);
					if (array[a-1] < 0)
						negatives.adjust(a, -1);
				}
				else if (array[a-1] > 0 && b < 0)
				{
					negatives.adjust(a, 1);
				}
				else if (array[a-1] < 0 && b>0) negatives.adjust(a, -1);
				array[a-1] = b;
			}
			else 
			{
				if (zeros.rsq(a, b))
					cout  << 0;
				else if (negatives.rsq(a, b) % 2 == 0)
					cout << '+';
				else
					cout << '-';
			}
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}

/* NAIVNI TLE
int main() {
	int K, N, t, a, b;
	char c;
	while (cin >> N >> K) {
		int A[100000];
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}
		for (int i = 0; i < K; i++)
		{
			
			cin >> c >> a >> b;
			if (c == 'C') 	A[a - 1] = b;
			else 
			{
				bool M = false, Z = false;
				for (int j = a - 1; j < b; j++) 
				{
					if (A[j] < 0) M = !M;
					if (A[j] == 0) Z = true;

				}
				if (Z) cout << "0";
				else if (M)cout << "-";
				else cout << "+";
			}
		
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}
*/