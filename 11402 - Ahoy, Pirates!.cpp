#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

ofstream o("Text.txt");

class fenwickTree {
public:
	vector<int> tree;
	int n;
	fenwickTree(int a)
	{
		n = a+1;
		tree = vector<int>(n, 0);
	}

	int RSQ(int i)
	{
		int sum = 0;
		for (; i; i -= (i&-i)) sum += tree[i];
		return sum;
	}
	int RSQ(int i, int j)
	{
		return RSQ(j) - (i == 1 ? 0 : RSQ(i));
	}

	void build(int val, int ind)
	{
		for (; ind<n ; ind += (ind&-ind))	tree[ind] += val;
	}

};

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << "Case " << i << ":\n";
		int Q = 1, M, T, q, x, y;
		char A;
		string s = "", temp;
		cin >> M;
		while (M--)
		{
			cin >> T >> temp;
			while (T--)
			{
				s = s + temp;
			}
		}
		int k = s.size();
		fenwickTree ft(k);
		for (int j = 0; j < k; j++)
		{
			char l = s[j];
			ft.build(l - '0', j + 1);
		}
		cin >> q;
		while (q--)
		{
			cin >> A >> x >> y;
			if (A == 'F')
			{
				for (int k = x; k <= y; k++)
				{
					if (s[k] == '1') continue;
					else {
						ft.build(1, k + 1);
						s[k] = '1';
					}
				}
			}
			else if( A == 'E')
			{
				for (int k = x; k <= y; k++)
				{
					if (s[k] == '0') continue;
					else {
						ft.build(-1, k + 1);
						s[k] = '0';
					}
				}

			}
			else if (A == 'I')
			{

				for (int k = x; k <= y; k++)
				{
					if (s[k] == '0')
					{
						ft.build(1, k + 1);
						s[k] = '1';
					}

					else {
						ft.build(-1, k + 1);
						s[k] = '0';
					}
				}

			}
			else {
				cout << "Q" << Q++ << ": " << ft.RSQ(x , y + 1) << "\n";
			}
		}
	}
	system("PAUSE");
	return 0;
}