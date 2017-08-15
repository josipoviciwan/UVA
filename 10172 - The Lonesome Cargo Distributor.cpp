#include<iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	int SET, N, S, Q, num, x;
	cin >> SET;
	while (SET--)
	{
		int ans = 0, size = 0;
		cin >> N >> S >> Q;
		vector<queue<int> > V(N);
		stack <int> carrier;
		for (int i = 0; i < N; i++)
		{
			cin >> num; 
			while (num--)
			{
				cin >> x;
				V[i].push(x); 
			}
		}
		for (int i = 0; i < N; i++)
			size += V[i].size();
		int station = 0;
		while (size)	
		{
			while (carrier.size() && (carrier.top() == station + 1 || V[station].size() < Q)) //Tu si sjebo, moze q bit pun, ali da praznis stack, jer je na odg. stanici
			{
				int curr = carrier.top();
				if (curr != station + 1)
					V[station].push(curr);

				carrier.pop();
				ans++;
			}
			while (carrier.size() < S && V[station].size()) 
			{
				carrier.push(V[station].front());
				V[station].pop();
				ans++;
			}
			size = 0;
			for (int i = 0; i < N; i++) 
			{
				size += V[i].size();
			}
			size += carrier.size(); //Ne gledaj samo queue nego i carriera, i on nosi terete koje treba rasporedit!!!
			if (size) {
				station = (++station) % N;
				ans += 2;
			}
		}
		cout << ans << endl;
	}
	system("PAUSE");
	return 0;
}