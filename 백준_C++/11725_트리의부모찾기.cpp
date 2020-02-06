/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11725
summary : 탐색으로 풀거다
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

int N;
vector <int>node[100001];
int id[100001];

void dfs(int p){
	for(auto ch : node[p]){
		if(id[ch] == 0){
			id[ch] = p;
			dfs(ch);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t = N;
	int a,b;
	while(t--){
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	id[1] = 1;
	dfs(1);
	for(int i = 2; i <= N;++i){
		cout<<id[i]<<endl;
	}
}