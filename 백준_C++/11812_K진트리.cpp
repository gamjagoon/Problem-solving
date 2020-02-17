/*
Date : 02/13/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11812
summary : LCA 이용
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

constexpr ll size = 1e18;
ll N;
int K,Q,last,M;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>K>>Q;
}


ll get_parent(ll a){
	if(a + K - 2 <= 0)return 0;
	return (a + K- 2) / K;
}

int main(){
	Input();

	ll a, b;
	while(Q--){
		cin>>a>>b;
		if (K == 1)
		{
			if(a >= b)cout<<a - b<<endl;
			else cout<<b - a<<endl;
			continue;
		}
		int res = 0;
		while(a != b){
			while(a > b){
				a = get_parent(a);
				res++;
			}
			while(b > a){
				b = get_parent(b);
				res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}