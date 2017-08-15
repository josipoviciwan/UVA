#include<set>
#include<iostream>
#include<utility>
#include<algorithm>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

ofstream o("Text.txt");
int wow = INT_MIN;

class segTree {
public:
	vector <int> tree;
	int n;

	segTree(int k) 
	{
		n = k;
		tree = vector<int>(2 * n, 0);
	}

	segTree(vector <int> &array)
	{
		n = array.size();
		tree = vector<int>(2 * n);
		copy(array.begin(), array.end(), &tree[0] + n);
		for (int i = n - 1; i > 0; i--)
			tree[i] = max(tree[i * 2], tree[2 * i + 1]);
		for (auto it : tree)
			cout << it << " ";
		cout << endl;
	}

	void update(int value, int index)
	{
		int i = index + n;
		tree[i] = value;
		while (i > 1) {
			i /= 2;
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}

	int RMQ(int left, int right) // [LEFT, RIGHT> interval"!!!
	{
	
		left += n;
		right += n;
		if (left == right) return tree[left-1];
		int m = INT_MIN;
		while (left < right)
		{
			cout << "LEFT: " << left << " RIGHT: " << right << endl;
			if (left & 1)
				m = max(m, tree[left++]);
			if (right & 1)
				m = max(m, tree[--right]);
			right >>= 1;
			left >>= 1;

		}
		return m;
	}
};

int main() {
	int n, q, k, l;
	while (cin >> n && n && cin >> q) {
		vector <int> V(n);
		for (int i = 0; i < n; i++)
			cin >> V[i];
	
		segTree st(n);
		st = segTree(V);
		for (int i = 0; i < n; i++)
			cout << i << "  ";
		cout << endl;

		while (q--) {
			cin >> k >> l;
			cout << st.RMQ(k , l ) << endl;
		}
	}
	system("PAUSE");
	return 0;
}
/*  TIME LIMIT EXCEED
int main() {
	int n, q, I, J, temp;
	while (cin >> n >> q && n)
	{
		unordered_map <int, int> A;
		unordered_map<int,int> B;
		int last, frstindex = 0, lastindex, x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (!i) last = x;
			if (x != last)
			{
				last = x;
				A[frstindex + 1] = i;
				B[i] = frstindex + 1;
				frstindex = i;
			}
			if (i == n - 1)
			{
				A[frstindex + 1] = i+1;
				B[i+1] = frstindex + 1;
			}
		}

		for (int i = 0; i < q ; i++)
		{
			int ans = 0;
			cin >> I >> J;

			for (int j = I; j <= J; j++) {
				int endofa = A[j];
				int startofb = B[j];
				if (endofa)
				{
					int c = min(endofa, J);
					ans = max(ans, c - j + 1);
				}
				
				if (startofb) {
					int d = max(startofb, I);
					ans = max(ans, j - d + 1);
				}
			}
			if (!ans) ans = J - I + 1;
			 o << ans << endl;
		}
	}
	system("PAUSE");
	return 0;
}
*/