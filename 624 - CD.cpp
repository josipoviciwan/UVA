// 624 - CD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
#include<bitset>
using namespace std;

int main()
{
	int N, n;
	while (cin >> N)
	{
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int MAX = -1, cnt = -1;
		int ans = 0;
		for (long int i = 0; i < 2<<n; i++)
		{
			int sum = 0;
			bitset<21> bs(i);
			for (int j = 0; j < v.size(); j++)
			{
				if (bs[j]) sum += v[j];
			}
			if (sum >= MAX && sum <= N )
			{
				MAX = sum;
				ans = i;
			}
		}	
		for (int i = 0; i <n; i++)
		{
			if (ans%2 )
				cout << v[i] <<" ";
			
			ans /= 2;
		}
		cout <<"sum:"<< MAX<<endl;
	}
	system("PAUSE");
	return 0;
}

