/*
Date : 02/14/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2780
summary : 특정한 중복조합의 갯수
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int dp[1001][10];
int N;
constexpr int dumy = 1234567;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;cin>>tc;
	for(int i = 0; i <= 9; i++){
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 1000; i++)
	{
		dp[i][0] = dp[i - 1][7] % dumy;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][4])% dumy;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5])% dumy;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][6])% dumy;
		dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7])% dumy;
		dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8])% dumy;
		dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9])% dumy;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0])% dumy;
		dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9])% dumy;
		dp[i][9] = (dp[i - 1][8] + dp[i - 1][6])% dumy;
	}
	while (tc--)
	{
		cin>>N;
		int res = 0;
		for(int i = 0 ; i <= 9 ; ++i){
			res += dp[N][i];
			res %= dumy;
		}
		cout<<res<<endl;
	}
	
}