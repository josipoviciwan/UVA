#include<iostream>
#include<map>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;
ofstream O("Text.txt");


int main()
{
	int N, S;
	cin >> N;
	while (N--) {
		cin >> S;
		map <long int, int> M;
		int cnt = 0;
		int min = 0;
		long int*s = new long int[1000000];
		for (int i = 0; i < S; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < S; i++) 
		{
			set <long int> P;
			for (int j = 0; j + i < S; j++) 
			{
				P.insert(s[j + i]);
				if (P.size() == j + 1) {
					cnt = max(cnt, j+1);
				}
				else break;
			}


		}
		cout << cnt <<"\n";
	}

	system("PAUSE");
	return 0;
}

