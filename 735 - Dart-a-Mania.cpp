#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;


int main()
{
	int n, sum;
	bool first = true;
	string t = "**********************************************************************";
	set <int> S;
	for (int i = 0; i <= 20; i++) { S.insert(i);  S.insert(3 * i);	S.insert(2 * i); }
	S.insert(50);
	vector<int> V(S.size());
	auto it = S.begin();
	for (int i = 0; i < S.size(); i++)
	{
		V[i] = *it;
		it++;
	}
	while (cin >> n && n > 0)
	{
		set<set<int> > SS;
		int perm = 0;
		int N = V.size();
		for (int i = 0; i < N && V[i] <= n; i++)
			for (int j = 0; j < N && V[j] + V[i] <= n; j++)
				for (int k = 0; k < N && V[i] + V[j] + V[k] <= n; k++)
					if (V[i] + V[j] + V[k] == n)
					{
						perm++;
						set<int>temp;
						temp.insert(V[i]);
						temp.insert(V[j]);
						temp.insert(V[k]);
						SS.insert(temp);
					}
		if (!first) cout << t << endl;
		first = false;
		if (!perm)cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
		else {
			cout<< "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << SS.size() << "." << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << "." << endl;
		}
	}
	cout << t << endl << "END OF OUTPUT"<<endl;
	system("PAUSE");
	return 0;
}