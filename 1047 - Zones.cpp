#include<vector>
#include<iostream>
#include<set>
#include<bitset>
#include<fstream>
using namespace std;

ofstream o("Text.txt");

int main()
{

	int all, built, cnt = 1, m, common, index, N;
	while (cin >> all >> built && all && built)
	{
		vector<int> stations(all);
		for (int i = 0; i < all; i++)
			cin >> stations[i];
		cin >> m;
		vector<int> shared(all);
		vector<vector<int>> V(all, vector<int>(all, 0));
		while (m--)
		{
			cin >> common;
			for (int i = 0; i < common; i++) //Spremi indexe onih koji dijele podrucja
				cin >> shared[i];
			cin >> N;
			for (int i = 0; i < common; i++)
				for (int j = i + 1; j < common; j++)
					V[shared[i] - 1][shared[j] - 1] -= N;

		}
		long int MAX = -1;
		set<int> ans;
		long int sum;
		for (int i = 0; i < 1 << built; i++) {
			bitset<20> bs(i);
			if (bs.count() == built) {
				 sum = 0;
				int  temp = i;
				set <int>t;
				for (int j = 0; j < all; j++)
				{
					if (temp % 2)
						sum += stations[j];
					temp /= 2;
					t.insert(j + 1);
				}
				if (sum > MAX)
				{

					ans = t;
					MAX = sum;

				}
			}
		}

		for (auto it : ans)
			o << it << " ";
		o << MAX<<endl;
	}

	system("PAUSE");
	return 0;
}