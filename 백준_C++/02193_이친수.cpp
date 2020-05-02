/*
Date : 05/01/2020
version : gcc 6.3.0 c++14
summary : scc
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

long long dp[91][2];

int main() {
	io;
	int n;cin>>n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	if(n ==1) cout<<1;
	else{
		for(int i = 2; i <= n;i++){
			dp[i][0] = dp[i-1][1];
			dp[i][1] += dp[i-1][0];
			dp[i][0] += dp[i-1][0];
		}
		cout<<dp[n][0]+dp[n][1];
	}
}