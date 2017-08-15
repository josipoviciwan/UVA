#include<iostream>
#include<set>
#include<string>
#include<utility>
using namespace std;

int main() 
{
	string s;
	int num, t, K,cnt = 0;
	set <pair<pair<int,int>,int>> PQ; 
		while (cin >> s && s != "#")
		{
			cin >> num >> t;
			PQ.insert(make_pair(make_pair(t, num), t));
		}
		cin >> K; 
		for (int i = 0; i < K; i++)
		{
			auto it = PQ.begin();
			int a = (*it).first.first;
			int b = (*it).first.second;
			int c = (*it).second;
			cout << b << endl;
			PQ.insert(make_pair(make_pair(a + c, b), c));
			PQ.erase(it);
			
		}
	system("PAUSE");
	return 0;
}