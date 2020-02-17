/*
Date : 02/14/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11727
summary : 다이나믹프로그래밍
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int dp[1001] = {0,};
int n;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
}

int solve(int n){
	if(dp[n] == 0){
		return dp[n] = (solve(n-1) + solve(n-2)*2) % 10007;
	}
	return dp[n] % 10007;
}

int main(){
	Input();
	dp[1] = 1;
	dp[2] = 3;
	cout<<solve(n)%10007;
	return 0;
}