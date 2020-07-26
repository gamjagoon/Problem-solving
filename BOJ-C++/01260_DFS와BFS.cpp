#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>g[1001];
bool ch[1001];
bool chh[1001];

void dfs(int s){
	if(!ch[s]){
		cout<<s<<" ";
		ch[s] = true;
		for(auto i : g[s]){
			dfs(i);
		}
	}
}

void bfs(int s){
	queue<int>q;
	chh[s] = true;
	q.push(s);
	int poped;
	while(!q.empty()){
		poped = q.front();q.pop();
		cout<<poped<<" ";
		for(auto i : g[poped]){
			if(!chh[i]){
				chh[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int E,V,S;
	cin>>E>>V>>S;
	int u,v;
	for (auto i = 0;i < V; ++i) {
		cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (auto i = 1;i <= E; ++i) {
		sort(g[i].begin(),g[i].end(),[](int l,int r){return l < r;});
	}
	dfs(S);cout<<"\n";
	bfs(S);
}
