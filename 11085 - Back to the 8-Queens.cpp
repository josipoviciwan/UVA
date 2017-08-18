#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<fstream>
using namespace std;

vector<vector<int>> V;
int t = INT_MAX;
ofstream o("Text.txt");

int taken(int col, int row, vector<int>array)
{
	for (int i = 0; i < col; i++)
 		if (abs(i - col) == abs( array[i] - row) || row == array[i] ) return 1;
	return 0;
}

void solve(vector<int> array, vector<int> ans)
{
	int cnt = 0;
	if (ans.size() == 8)
	{
		V.push_back(ans);
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (!taken(ans.size() , i, ans))
		{
			vector<int>temp(ans);
			temp.push_back(i);
			solve(array, temp);
		}
	}
}


int main()
{
	int c = 1;
	vector <int> array(8), empty;
	solve(array, empty);
	while (cin.peek() != EOF) //JEBENO SMEÆE
	{
		int last , cnt = 0, ans = INT_MAX;
		for (int i = 0; i < 8; i++)
		{
			cin >> last;
			array[i] = last -1 ;

		}
		for (int i = 0; i < V.size(); i++)
		{
			cnt = 0;
			for (int j = 0; j < 8; j++)
			{
				if (array[j] != V[i][j])cnt++;
			}
			ans = min(ans, cnt);
		}
		cout <<"Case "<<c++<<": "<<ans << "\n";
		cin.ignore();
	}
	system("PAUSE");
	return 0;
}


/*
 TLE
	 int main()
 {
	 vector<int>temp = { 1,2,3,4,5,6,7,8 };
	 vector<vector<int>> good_ones;
	 do {
		 bool is_good = true;
		 for (int i = 0; i < 8; i++)
		 {
			 for (int j = i + 1; j < 8; j++)
			 {
				 int  a = abs(i - j), b = abs(temp[i] - temp[j]);
				 if (temp[i] == temp[j] || a == b)
				 {
					 is_good = false;
					 continue;
				 }

			 }
			 if (!is_good)continue;
		 }
		 if (is_good) good_ones.push_back(temp);

	 } while (next_permutation(temp.begin(), temp.end()));

	 int cnt = 1;
	 while (1) {

		 vector<int> A(8);
		 int ans = INT_MAX;
		 for (int i = 0; i < 8; i++)
			 cin >> A[i], temp[i] = i + 1;
		 for (int i = 0; i < good_ones.size(); i++)
		 {
			 int cnt = 0;
			 for (int j = 0; j < 8; j++)
				 if (good_ones[i][j] != A[j]) cnt++;
			 ans = min(cnt, ans);


		 }
		 cout << "Case " << cnt++ << ": " << ans << endl;

	 }
	 system("PAUSE");
	 return 0;
 }
 */
