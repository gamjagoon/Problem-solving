/*
Date : 03/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1764
summary : scc
*/
#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

set<string>A;
set<string>names;

int main() {
	io
	int N,M;
	cin>>N>>M;
	string tmp;
	mfor(i,0,N){
		cin>>tmp;
		A.insert(move(tmp));
	}
	mfor(i,0,M){
		cin>>tmp;
		if(A.find(tmp) != A.end()){
			names.insert(move(tmp));
		}
	}
	cout<<names.size()<<endl;
	for(auto i : names){
		cout<<i<<endl;
	}
	return 0;
}