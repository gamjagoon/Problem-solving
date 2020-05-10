/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2240
summary : 
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

int N,W;
int dp[3][1001][32];
int arr[1001];

int main(){
	fastio;
	cin>>N>>W;
	mfor(i,1,N){
		cin>>arr[i];
	}
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= W+1; ++j){
			if( arr[i] == 1){
				dp[1][i][j] = max(dp[1][i-1][j] +1,dp[2][i-1][j-1] + 1);
				dp[2][i][j] = max(dp[1][i-1][j-1],dp[2][i-1][j]);
			}
			else {
				if(i == 1 && j == 1){
					continue;
				}
				dp[1][i][j] = max(dp[2][i-1][j-1],dp[1][i-1][j]);
				dp[2][i][j] = max(dp[2][i-1][j]+1,dp[1][i-1][j-1]+1);
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= W+1;++i){
		res = max(res,max(dp[1][N][i], dp[2][N][i]));
	}
	cout<<res;
}
