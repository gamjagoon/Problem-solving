/*
Date : 02/07/2020
version : gcc 6.3.0 c++14
problem : 
summary : 
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define mfor(i,A,e) for(auto i = A; i <= e; ++i)
#define MyAbs(a) (a)>0 ? (a):-(a)
using namespace std;

int A[20][20],N;
int ans = 987654321;

int bitcnt(int n){
	int ret = 0;
	while(n > 0){
		n -= n & (-n);
		ret++;
	}
	return ret;
}

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i,0,N-1){
		mfor(j,0,N-1){
			cin>>A[i][j];
		}
	}
}

void Solve(){
	int end = (1 << (N-1));
	for (int i = 0; i < end; i++)
	{
		if (bitcnt(i) != N / 2 - 1) continue;

		int state = i, sum_a = 0, sum_b = 0;
		state = (state << 1) | 1;

		for (int j = 0; j < N; j++)
		{
			if (state & (1 << j))
			{
				for (int k = j+1; k < N; k++)
				{
					if (state & (1 << k)) sum_a += A[j][k]+A[k][j];
				}
			}
			else
			{
				for (int k = j+1; k < N; k++)
				{
					if ((state & (1 << k)) == 0) sum_b += A[j][k]+A[k][j];
				}
			}
		}
		ans = min(ans, MyAbs(sum_a - sum_b));
		if (ans == 0) break;
	}
}

int main(){
	Input();
	Solve();
	cout<<ans<<endl;
	return 0;
}