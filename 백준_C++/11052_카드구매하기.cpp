/*
Date : 02/01/2020
version : gcc 6.3.0 c++14
problem : 카드구매하기
summary : 다이나믹 프로그래밍
*/
#include <iostream>
#define mmax(a,b) a > b ? a : b;
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

ll dp[1001] = {0 , };
ll p[10001];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	mfor(i,1,n){
		cin>>p[i];
	}
	mfor(i,1,n){
		mfor(j,1,i){
			dp[i] = mmax(dp[i-j]+p[j],dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
}