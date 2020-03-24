#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr int M = 2010,inf = 1e9+7,s = 0,e = 2001;
vector<int> g[M];
using pii = pair<int,int>;

int cap[M][M],flow[M][M];
int par[M];
int n,m,ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		cap[s][i] = 1;
		g[s].push_back(i);
		g[i].push_back(s);
		int t;cin>>t;
		for (auto j = 0; j < t; j++)
		{
			int tt;cin>>tt;
			tt += 1000;
			g[i].push_back(tt);
			g[tt].push_back(i);
			cap[i][tt] = 1;
		}
	}

	for (auto i = 1000; i < 1000+m; i++)
	{
		g[i].push_back(e);
		g[e].push_back(i);
		cap[i][e] = 1;
	}
	for(int i = 1;;i++){
		memset(par,-1,sizeof(par));
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int now = q.front();q.pop();
			for(auto nxt : g[now]){
				if(par[nxt] == -1&& cap[now][nxt] - flow[now][nxt] > 0) {
					q.push(nxt); par[nxt]= now;
					if(nxt == e) break;
				}
			}
		}
		if(par[e] == -1) break;

		int cost = inf;
		for (auto j = e; j != s; j=par[j])
		{
			cost = min(cost,cap[par[j]][j]-flow[par[j]][j]);
		}

		for(int j = e; j != s; j = par[j]) {
			flow[par[j]][j] += cost;
			flow[j][par[j]] -= cost;
		}
		ans += cost;
	}
	cout<<ans;
}
