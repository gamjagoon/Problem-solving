/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11400
summary : 단절선
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

constexpr int Max = 100000;

using pii = pair<int,int>;

int N,E,dfsn[Max+1],cnt = 0;
vector<vector<int> > g;
vector<pii> bridge;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>E;
	g.resize(N+1);
	mfor(i,0,E-1){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

int dfs(int curr, int prev = -1)
{
	int res = dfsn[curr] = ++cnt;
	for(auto nxt : g[curr])if(nxt != prev){
		if(dfsn[nxt]) {
			res = min(res, dfsn[nxt]);
			continue;
		}
		int df = dfs(nxt, curr);
		if(df > dfsn[curr]){
			if(curr > nxt){
				bridge.emplace_back(nxt,curr);
			}
			else{
				bridge.emplace_back(curr,nxt);
			}
		}
		res = min(res, df);
	}
	return res;
}


int main(){
	Input();
	mfor(i,1,N){
		if(!dfsn[i]){
			dfs(i);
		}
	}
	cout<<bridge.size()<<endl;
	sort(bridge.begin(),bridge.end());
	for(auto &curr: bridge){
		cout<<curr.first<<' '<<curr.second<<endl;
	}
	return 0;
}