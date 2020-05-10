/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/3682
summary : 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

constexpr int Max = 20001;

int tc;
int N,M;

vector<int> g[Max];
vector<vector<int> >sg;
int dfsn[Max],cnt,in[Max],out[Max],loc[2],s,scc[Max];
stack <int> st;

void Input(){
	cin>>N>>M;
	cnt = 0;
	sg.clear();
	sg.resize(N+1);
	loc[0] = loc[1] = 0;
	cnt = 0;
	s = 0;
	mfor(i,1,N){
		g[i].clear();
		dfsn[i] = 0;
		scc[i] = 0;
		in[i] = 0;
		out[i] = 0;
	}
	int a,b;
	mfor(i,0,M-1){
		cin>>a>>b;
		g[a].push_back(b);
	}
}

int dfs(int curr){
	dfsn[curr] = ++cnt;
	st.push(curr);
	int res = dfsn[curr];
	for(auto nxt:g[curr]){
		if(dfsn[nxt] == 0){
			res = min(res, dfs(nxt));
		}
		else if(!scc[nxt])res = min(res,dfsn[nxt]);
	}
	if(res == dfsn[curr]) {
		int tmp;
		s++;
		while(1) {
			tmp = st.top();
			scc[tmp] = s;
			st.pop();
			if(tmp == curr)break;
		}
	}
	return res;
}
int Solve(){
	int ret = 0;
	for(int i = 1; i <= N; ++i){
		if(!dfsn[i]){
			dfs(i);
		}
	}
	mfor(i,1,N){
		for(auto j : g[i]){
			if(scc[i] != scc[j]){
				sg[scc[i]].push_back(scc[j]);
			}
		}
	}
	mfor(i,1,s){
		for(auto j : sg[i]){
			in[j]++;
			out[i]++;
		}
	}
	mfor(i,1,s){
		loc[0] += !in[i];
		loc[1] += !out[i]; 
	}

	if(s == 1){
		ret = 0;
	}
	else{
		ret = max(loc[0],loc[1]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>tc;
	while(tc--){
		Input();
		if(M == 0){
			cout<<N<<endl;
		}
		else cout<<Solve()<<endl;
	}
}