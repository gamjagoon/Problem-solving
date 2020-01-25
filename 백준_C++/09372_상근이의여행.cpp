#include <iostream>
#include <queue>
#include <vector>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

constexpr int max_node = 1001;

typedef pair<int,int>pii;

bool visit[max_node];
vector<pii> vc[max_node];
int n,m;

void prim(int start){
	visit[start] = true;

	priority_queue<pii, vector<pii>,greater<pii> >pq;
	int sz = vc[start].size();
	int next,nextcost;
	mfor(i,0,sz-1){
		next = vc[start][i].first;
		nextcost = vc[start][i].second;
		pq.push(pii(nextcost, next));
	}
	int ans = 0,nowcost,now;
	while(!pq.empty())
	{
		now = pq.top().second;
		nowcost = pq.top().first;
		pq.pop();
		if(visit[now])continue;
		visit[now] = true;

		ans += nowcost;

		sz = vc[now].size();
		mfor(i,0,sz-1){
			next = vc[now][i].first;
			nextcost = vc[now][i].second;
			pq.push(pii(nextcost, next));
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		mfor(i,1,n){
			visit[i] = false;
			vc[i].clear();
			vc[i].resize(0);
		}
		int a,b;
		mfor(i,0,m-1){
			cin>>a>>b;
			vc[a].push_back(pii(b,1));
			vc[b].push_back(pii(a,1));
		}
		prim(1);
	}
}