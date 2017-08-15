#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {

	int C;
	cin >> C;
	string S, T;
	for (int i = 1; i <= C; i++) {
		int cnt , Sone = 0 , Tone=0 ;
		cin >> S >> T; 
		int qm2one = 0,qm2zero = 0,zero2one = 0 , one2zero = 0;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '1') Sone++;
			if (T[j] == '1') Tone++;
			if (S[j] == '0' && T[j] == '1') zero2one++;
			if (S[j] == '1' && T[j] == '0') one2zero++;
			if (S[j] == '?' && T[j] == '1')  qm2one++; 
			if (S[j] == '?' && T[j] == '0')  qm2zero++; 
		}
		cnt = (Sone <= Tone) ? max(zero2one,one2zero)  + qm2one + qm2zero : -1;
		cout << "Case " << i << ": " << cnt  << endl;
	}
	system("PAUSE");
	return 0;
}