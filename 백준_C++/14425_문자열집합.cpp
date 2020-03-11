/*
Date : 03/06/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/14425
summary : 해슁
*/
#include <iostream>
#include <unordered_set>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
unordered_set<string>keys;
int N,M;

void solve(){
	cin>>N>>M;
	int res = 0;
	string tmp;
	mfor(i,0,N){
		cin>>tmp;
		keys.insert(move(tmp));
	}
	mfor(i,0,M){
		cin>>tmp;
		if(keys.find(tmp) != keys.end()){
			res++;
		}
	}
	cout<<res;
}

int main() {
	io
	solve();
}