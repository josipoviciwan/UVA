#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	int n, ans = 0, curr, j;
	vector <int>V;

	while (cin >> n)
	{
		V.push_back(n);
	}
	int t = V.size();
	vector<int> lis(t), temp(t), R(t, -1);

	temp[0] = V[0];
	for (int i = 1; i < t; i++)
	{


		if (V[i] > temp[ans])
			ans++, temp[ans] = V[i], lis[ans] = i, R[i] = lis[ans - 1];
		else if (V[i] < temp[0]) temp[0] = V[i], lis[0] = i;
		else
		{
			j = lower_bound(temp.begin(), temp.begin() + ans, V[i]) - temp.begin();
			temp[j] = V[i], lis[j] = i, R[i] = lis[j - 1];
		}
	}
	cout << ans + 1 << endl << '-' << endl;
	curr = lis[ans];
	set<int>S;
	while (curr >= 0)
		S.insert(V[curr]), curr = R[curr];
	for (auto it : S)
		cout << it << endl;
	system("PAUSE");
	return 0;
}




/* TLE O(n^2) algorithm
int main()
{
	vector<int> V;
	vector<int> lis;
	vector<int>indexes;
	set<int> S;
	int n, j, ans = 0, index;
	while (cin >> n)
	{
		V.push_back(n);
		lis.push_back(1);
		j = lis.size() - 1;
		indexes.push_back(j);
		for (int i = 0; i < j; i++)
		{
			if (V[j] > V[i] && lis[i] + 1 >= lis[j]) indexes[j] = i, lis[j] = lis[i] + 1;
		}
		if (lis[j] >= ans) ans = lis[j], index = j;
	}
	while (index != indexes[index])
		S.insert(V[index]), index = indexes[index];
	S.insert(V[index]);
	cout << ans << endl << "-" << endl;
	for (auto it : S)
		cout << it << endl;
	system("PAUSE");
	return 0;
}
*/