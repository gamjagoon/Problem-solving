/*
Date : 02/13/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/3176
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
constexpr int size = 100001;
int N;
vector<line>g[size];
int dp[size][18];
int level[size];
int maxdist[size][18];
int mindist[size][18];
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
	for(auto j : g[i]){
		if(!ch[j.next]){
			dp[j.next][0] = i;
			mindist[j.next][0] = j.len;
			maxdist[j.next][0] = j.len;
			dfs(j.next, d+1,D + j.len);
		}
	}
}

line lca(int a,int b) {
	int e = INT32_MIN;
	int s = INT32_MAX;
	if(level[a] > level[b]){
		swap(a, b);
	}
	int diff = level[b] - level[a];
	for(int i = 0; diff;++i){
		if(diff & 1){
			e = max(e, maxdist[b][i]);
			s =  min(s,mindist[b][i]);
			b = dp[b][i];
		}
		diff>>=1;
	}
	if(a == b)return {s,e};
	for(int i = 17; i >= 0; --i){
		if(dp[b][i] != dp[a][i]){
			s = min({s,mindist[b][i],mindist[a][i]});
			e = max({e,maxdist[b][i],maxdist[a][i]});
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	s = min({s,mindist[b][0],mindist[a][0]});
	e = max({e,maxdist[b][0],maxdist[a][0]});
	return {s,e};
}

void make_table() {
	for(int j = 1;j < 18; ++j){
		for(int i = 1; i <= N; ++i){
			dp[i][j] = dp[dp[i][j-1] ][j-1];
			mindist[i][j] = min(mindist[i][j-1], mindist[dp[i][j-1]][j-1]);
			maxdist[i][j] = max(maxdist[i][j-1], maxdist[dp[i][j-1]][j-1]);
		}
	}
}

int main(){
	Input();
	dfs(1,0,0);
	make_table();
	int M;
	cin>>M;
	int a,b;
	line ret;
	while(M--){
		cin>>a>>b;
		line ret = lca(a,b);
		cout<<ret.next<<" "<<ret.len<<endl;
	}
}