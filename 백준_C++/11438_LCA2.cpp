/*
Date : 02/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11438
summary : lca 알고리즘
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
constexpr int size = 1e5 + 5;
int N,M;
vector<int> g[size];
int parent[size][30];
int depth[size];
bool visit[size];

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	int a,b;
	mfor(i,0,N-2){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void dfs(int v, int d){
	visit[v] = 1;
	depth[v] = d;
	for(auto i : g[v]){
		if(!visit[i]){
			parent[i][0] = v;
			dfs(i,d+1);
		}
	}
}


//정점의 갯수는 N개이다 따라서 
//i 는 정점의 갯수를 따라서 하나씩 순회하는 변수이다
// j 는 parent[i][j] 에서 2^j 번쩨 조상을 따라서 순차적으로 순회하는 방식이다 
void make_table() {
	mfor(j,1,29){
		mfor(i,1,N){
			parent[i][j] = parent[parent[i][j-1] ][j-1];
		}
	}
}


int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = 0 ; diff; i++) {
		if(diff & 1) u = parent[u][i];
		diff>>=1;
	}
	if(u == v)return u;
	for(int i = 29; i >= 0; --i){
		if(parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
	}
	return parent[u][0];
}

int main(){
	Input();
	dfs(1,0);
	make_table();
	cin>>M;
	int a,b;
	while(M--){
		cin>>a>>b;
		cout<<lca(a, b)<<"\n";
	}
	return 0;
}