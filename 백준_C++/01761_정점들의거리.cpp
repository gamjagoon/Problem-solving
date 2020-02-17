/*
Date : 02/13/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1761
summary : LCA
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
struct line {
	int next,len;
};
constexpr int size = 40001;
int N;
vector<line>g[size];
int dp[size][27];
int level[size];
int dist[size];
bool ch[size];

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	int a,b,l;
	mfor(i,0,N-2){
		cin>>a>>b>>l;
		g[a].push_back({b,l});
		g[b].push_back({a,l});
	}
}

void dfs(int i,int d,int D){
	ch[i] = true;
	level[i] = d;
	dist[i] = D;
	for(auto j : g[i]){
		if(!ch[j.next]){
			dfs(j.next, d+1,D + j.len);
			dp[j.next][0] = i;
		}
	}
}

int lca(int a,int b) {
	if(level[a] > level[b]){
		swap(a, b);
	}
	int diff = level[b] - level[a];
	for(int i = 0; diff;++i){
		if(diff & 1)b = dp[b][i];
		diff>>=1;
	}
	if(a == b)return b;
	for(int i = 26; i >= 0; --i){
		if(dp[b][i] != dp[a][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[b][0];
}

void make_table() {
	for(int j = 1;j < 27; ++j){
		for(int i = 1; i <= N; ++i){
			dp[i][j] = dp[dp[i][j-1] ][j-1];
		}
	}
}

int main(){
	Input();
	dfs(1,0,0);
	make_table();
	int M;
	cin>>M;
	int a,b,L,res;
	while(M--){
		cin>>a>>b;
		res = 0;
		L = lca(a,b);
		cout<<dist[a] + dist[b] - dist[L]*2<<endl;
	}
}