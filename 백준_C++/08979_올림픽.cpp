/*
Date : 02/16/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/8979
summary : 정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

typedef long long ll;
typedef pair<int,long long>pii;

int N,K;
vector<pii>D;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>K;
	ll tmp = 0;
	mfor(i,1,N){
		int t;
		ll a,b,c;
		cin>>t>>a>>b>>c;
		tmp = c;
		tmp += b * 1000000;
		tmp += a * 1000000000000;
		D.push_back({t,tmp});
	}
}

bool com(pii &a, pii &b){
	return a.second > b.second;
}

int main(){
	Input();
	sort(D.begin(),D.end(),com);
	int now,prev = -1;
	int res = 0;
	int cal = 0;
	for(auto i : D){
		now = i.second;
		if(now != prev){
			res++;
			res+=cal;
			cal = 0;
		}
		else cal++;
		prev = now;
		if(i.first == K)break;
	}
	cout<<res<<endl;
	return 0;
}