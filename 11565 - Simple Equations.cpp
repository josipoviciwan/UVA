#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;

ofstream o("Text.txt");

int main()
{
	int N, A, B, C;
	cin >> N;
	while (N--)
	{
		set<int> div;
		cin >> A >> B >> C;
		for (int i = 1; i < sqrt(B); i++)
		{
			if (B%i == 0)
			{
				div.insert(i);
				div.insert(-i);
				div.insert(B / i);
				div.insert(-B / i);
			}
		}
		set<set<long int>> SS;
		vector<int> v(div.begin(), div.end());
		int size = v.size();
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				for (int k = 0; k < size; k++)
					if (v[i] + v[j] + v[k] == A && v[i] * v[j] * v[k] == B && pow(v[i], 2) + pow(v[j], 2) + pow(v[k], 2) == C)
					{
						set<long int> temp;
						temp.insert(v[i]);
						temp.insert(v[j]);
						temp.insert(v[k]);
						if (temp.size() == 3)
							SS.insert(temp);
					}
		
		if (SS.empty() )cout  << "No solution.";
		else {
			auto it = *SS.begin();
			for (auto it1 : it) {
				if (it1 ==  * it.begin()) cout << it1;
				else cout<< " "<< it1 ;
			}
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}