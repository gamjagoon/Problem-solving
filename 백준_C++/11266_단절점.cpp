/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11266
summary : 단절점
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

constexpr int Max = 100000;

int N,E,dfsn[Max+1],cnt = 0;
bool cut[Max+1];
vector<vector<int> > g;

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

int dfs(int here, bool r)
{
	dfsn[here] = ++cnt; int ret = dfsn[here];
	int child = 0;
	for(auto to : g[here]){
		if(!dfsn[to]){
			child++;
			int df = dfs(to, 0);
			if(!r && df >= dfsn[here])cut[here] = true;
			ret = min(ret, df);
		}else{
			ret = min(ret, dfsn[to]);
		}
	}
	if(r && child > 1)cut[here] = true;
	return ret;
}


int main(){
	Input();
	mfor(i,1,N){
		if(!dfsn[i]){
			dfs(i,1);
		}
	}
	int res = 0;
	mfor(i,1,N){
		if(cut[i]){
			res++;
		}
	}
	cout<<res<<endl;
	mfor(i,1,N){
		if(cut[i]){
			cout<<i<<' ';
		}
	}
	return 0;
}