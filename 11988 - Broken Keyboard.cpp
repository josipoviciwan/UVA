#include<iostream>
#include<string>
#include<list>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while (getline(cin, s, '\n')) {
		list <string> L;
		list<string>::iterator it ;
		int j = 0;
		int z;
		while (j < s.size())
		{
			int a = s.find_first_of('[', j);
			int b = s.find_first_of(']', j);
			if (a + 1 && b + 1)
			{
				z = min(a, b);
			}
			else if (a == b) z = s.size();
			else {
				z = max(a, b);
			}
			if(j)
				switch (s[j - 1])
				{
				case '[':it = L.begin(); break;
				case ']':it = L.end(); break;
				}
			else it = L.end();
			string temp = s.substr(j, z - j);
			L.emplace(it, temp);
		j = z + 1;
		}
		for (auto it = L.begin(); it != L.end(); it++)
			cout<< *it;
		cout << endl;
	}
	system("PAUSE");
	return 0;
}