#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define x first
#define y second
#define INF 987654321
using namespace std;

typedef pair<int, int> p;
int cost[801][801];
int N,E,A, B;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i < 801;++i)
	{
		for (int j = 1; j < 801; ++j)
		{
			cost[i][j] = INF;
		}
	}
	cin >> N >> E;
	for (int i = 0; i < E;++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
		cost[b][a] = min(cost[b][a], c);
	}
	cin >> A >> B;
}

long long dijkstra(int s,int e)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >pq;
	bool ch[801] = {false};
	int dist[801];
	for (int i = 1; i <= N; ++i)
	{
		dist[i] = INF;
	}
	dist[s] = 0;
	pq.push({0, s});
	while(!pq.empty())
	{
		int now = pq.top().y;
		int c = pq.top().x;
		pq.pop();
		if(ch[now])
			continue;
		ch[now] = true;
		if(c > dist[now])
			continue;
		if(now == e)
			return c;
		for(int i = 1; i <= N;++i)
		{
			if(!ch[i] && dist[i] > dist[now]+ cost[now][i])
			{
				dist[i] = dist[now] + cost[now][i];
				pq.push({dist[i],i});
			}
		}
	}
	return INF;
}

int main()
{
	init();
	long long res = min(dijkstra(1, A) + dijkstra(A, B) + dijkstra(B, N),dijkstra(1, B) + dijkstra(B, A) + dijkstra(A, N) );
	if(res > INF)
		cout << -1;
	else
		cout << res;
	return 0;
}