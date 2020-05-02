/*
Date : 05/01/2020
version : gcc 6.3.0 c++14
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

long long dp[10000][4];
vector<int>res;

int main() {
	io;
	int t; cin>>t;
	int M = 0;
	while(t--){
		int tmp;cin>>tmp;
		res.push_back(tmp);
		if(M < tmp)M = tmp;
	}
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[2][1] = 1;
	dp[3][3] = 1;
	dp[3][1] = 2;
	for(int i = 4; i <= M;i++){
		dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
		dp[i][2] = dp[i-2][2] + dp[i-2][3];
		dp[i][3] = dp[i-3][3];
	}
	for(auto i : res){
		cout<<dp[i][3]+dp[i][1]+dp[i][2]<<endl;
	}
}