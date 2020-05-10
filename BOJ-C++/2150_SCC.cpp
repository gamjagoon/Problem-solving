/*
Date : 02/22/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2150
summary : 
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;

constexpr int Max = 10010;

int V,E,cnt,par[Max], Sccsum;
vector<int> adj[Max];
bool finished[Max];
stack<int> s;
vector<vector<int> >SCC;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>V>>E;
	for(int i = 0; i < E; ++i) {
		int from, to;
		cin>>from>>to;
		adj[from].push_back(to);
	}
}

int dfs(int curr)
{
	par[curr] = ++cnt;
	s.push(curr);

	int res = par[curr];
	for(auto next : adj[curr])
	{
		if(par[next ] == 0 ){
			res = min(res, dfs(next));
		}
		else if(!finished[next]){
			res = min(res, par[next]);
		}
	}

	if (res == par[curr])
	{
		vector<int> curSCC;

		while(1)
		{
			int t = s.top();
			s.pop();
			curSCC.push_back(t);
			finished[t] = true;
			if(t == curr){
				break;
			}
		}

		sort(curSCC.begin(), curSCC.end());

		SCC.push_back(curSCC);
		Sccsum++;
	}
	return res;
}

int main(){
	Input();
	for(int i = 1; i <= V; ++i){
		if(par[i] == 0){
			dfs(i);
		}
	}
	sort(SCC.begin(), SCC.end());

	cout<<Sccsum<<endl;

	for(auto& currSCC : SCC)
	{
		for(auto curr : currSCC){
			cout<<curr<<' ';
		}
		cout<<"-1\n";
	}
}