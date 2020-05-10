/*
Date : 02/23/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2003
summary : 투포인터
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

typedef long long ll;

ll M;
vector<ll> v;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N;
	cin>>N>>M;
	v.reserve(N+1);
	mfor(i,0,N-1){
		cin>>v[i];
	}
	int s = 0, e = 0;
	int res = 0;
	ll tmp = 0;
	while(1){
		if(tmp >= M)tmp -= v[s++];
		else if(e == N)break;
		else tmp += v[e++];
		if(tmp == M)res++;
	}
	cout<<res<<endl;
	return 0;
}