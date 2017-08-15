#include<iostream>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;

ofstream O("Text.txt");

int main()
{
	int n;
	while (cin >> n)
	{
		stack<int> S;
		priority_queue<int> PQ;
		queue<int> Q;
		int a, b, s = 1, pq = 1, q = 1;
		while (n--)
		{
			cin >> a >> b;
			if (a == 1)
			{
				S.push(b);
				PQ.push(b);
				Q.push(b);
			}
			else
			{
				if ( S.empty()  || S.top() != b )
					s = 0;
				if ( PQ.empty() || PQ.top() != b)
					pq = 0;
				if ( Q.empty() || Q.front() != b)
					q = 0;
				if(S.size())
					S.pop();
				if (PQ.size())
					PQ.pop();
				if(Q.size())
					Q.pop();
			}
		}
		if (s + q + pq > 1)
			cout << "not sure" << endl;
		else if (s)
			cout << "stack" << endl;
		else if (q)
			cout << "queue" << endl;
		else if (pq)
			cout << "priority queue" << endl;
		else cout << "impossible" << endl;
	}

}