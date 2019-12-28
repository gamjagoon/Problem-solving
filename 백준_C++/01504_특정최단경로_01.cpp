#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N,E;
int node[802][802];
int dist_1[801] = {};
int dist_A[801] = {};
int dist_B[801] = {};

int A,B;

void init()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>E;
	int a,b,c;
	for(int i = 1; i <= N;++i){
		for(int j = 1; j <= N;++j){
			node[i][j] = INF;
		}
		dist_A[i] = INF;
		dist_B[i] = INF;
		dist_1[i] = INF;
	}
	for(int i = 0; i < E;++i)
	{
		cin>>a>>b>>c;
		if(c < node[a][b]){
			node[a][b] = c;node[b][a] = c;
		}
	}
	cin>>A>>B;
}

void dijkstra(int start,int *dist)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >pq;
	dist[start] = 0;
	pq.push({0,start});
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(cost > dist[now])continue;
		for(int i = 1 ; i <= N ; ++i){
			if(node[now][i] == INF )continue;
			int nextcost = cost + node[now][i];
			if(nextcost < dist[i]){
				dist[i] = nextcost;
				pq.push({nextcost,i});
			}
		}
	}
}

int main()
{
	init();
	dijkstra(1,dist_1);
	dijkstra(A,dist_A);
	dijkstra(B,dist_B);
	int AB = dist_1[A] + dist_A[B] + dist_B[N];
	int BA = dist_1[B] + dist_B[A] + dist_A[N];
	int res = AB > BA ? BA : AB;
	if(res >= INF || res < 0){
		cout<<-1<<'\n';
	} 
	else cout<<res<<'\n';
	return 0;
}