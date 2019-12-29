#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;
typedef pair<int,int> p;
int N,M;
int dir[201][201];
vector <p> g[201];
int dist[201];

void init()
{
	cin>>N>>M;
	while(M--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
}

void dijkstra(int start)
{
	for(int i = 1; i<=N;++i)dist[i] = INF;
	for(int i = 1; i<=N; ++i)dir[i][start] = -1;
	priority_queue<p,vector<p>,greater<p>>pq;
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(cost > dist[now])continue;
		for( auto i : g[now])
		{
			int nxt = i.first;
			int nxtcost = cost + i.second;
			if(nxtcost < dist[nxt]){
				dist[nxt] = nxtcost;
				pq.push(make_pair(nxtcost,nxt));
				dir[nxt][start] = now;
			}
		}
	}
}

int main()
{
	init();
	for(int i = 1; i <= N; ++i)
	{
		dijkstra(i);
	}
	for(int i = 1; i <= N;++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			if(dir[i][j] < 0) cout<<"- ";
			else cout<<dir[i][j]<<' ';
		}
		cout<<'\n';
	}
}


// input
// 6 8
// 1 3 7
// 1 5 1
// 1 6 6
// 2 5 1
// 2 6 2
// 3 4 7
// 3 5 6
// 5 6 4

// answer
// - 5 3 3 5 5 
// 5 - 5 5 5 6 
// 1 5 - 4 5 5 
// 3 3 3 - 3 3 
// 1 2 3 3 - 2 
// 2 2 2 2 2 - 