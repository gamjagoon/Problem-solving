/*
Date : 02/15/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/13511
summary : lca, 구간쿼리
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

constexpr int MAXN = 100100;
constexpr int L = 20;

int N,M,timer = 0;
ll euler[2*MAXN], lev[MAXN], dist[MAXN];
vector<pii> g[MAXN];
vector<int> idx[MAXN];
int par[MAXN][L];

void Init(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i,0,N-2){
		int a,b,c;cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
}

void dfs(ll x, ll pa, ll l,ll d){
	lev[x] = l;
	euler[++timer] = x;
	idx[x].push_back(timer);
	dist[x] = d;
	for(auto i : g[x]){
		if(i.first != pa){
			dfs(i.first, x,l+1,d+i.second);
			par[i.first][0] = x;
			euler[++timer] = x;
			idx[x].push_back(timer);
		}
	}
}

int pw2[L],lg2[MAXN*2];
pii dp[L][MAXN*2];

void make_table(){
	pw2[0] = 1;
	mfor(k,1,L-1)pw2[k] = pw2[k-1]*2;
	
	memset(lg2, -1, sizeof(lg2));
	mfor(k,0,L-1)if(pw2[k] < MAXN*2)lg2[pw2[k]] = k;
	mfor(i,1,MAXN*2-1)if(lg2[i] == -1)lg2[i] = lg2[i-1];
	
	for(int i=1;i<=2*N-1;i++) dp[0][i] = {lev[euler[i]], euler[i]};

	for(int k=1;k<L;k++){
		for(int i=1;i<=2*N-1;i++){
			if( i + pw2[k-1] > 2*N-1 ) continue;
			dp[k][i] = min(dp[k-1][i], dp[k-1][i+pw2[k-1]]);
		}
	}
	for(int i = 1; i < L; ++i){
		for(int j = 1; j <= N; ++j){
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}
}

int LCA(int u, int v){
	int l = idx[u][0],r =idx[v][0];
	if(l > r) swap(l,r);
	int k = lg2[r-l+1];
	return min(dp[k][l], dp[k][r-pw2[k]+1]).second;
}

int main(){
	Init();
	dfs(1,0,1,0);
	make_table();
	cin>>M;
	ll a,b,c,ca;
	ll d;
	while(M--){
		cin>>a>>b>>c;
		ca = LCA(b,c);
		if(a == 1){
			cout<<dist[b] + dist[c] - dist[ca] * 2<<endl;
		}
		else{
			cin>>d;
			ll diff = lev[b] - lev[ca];
			d--;
			if(d <=diff){
				for(int i = 0;d;++i ){
					if(d & 1)b = par[b][i];
					d>>=1;
				}
				cout<<b<<endl;
			}
			else{
				d = lev[c] - lev[ca] + diff - d;
				for(int i = 0;d;++i ){
					if(d & 1)c = par[c][i];
					d>>=1;
				}
				cout<<c<<endl;
			}
		}
	}
}