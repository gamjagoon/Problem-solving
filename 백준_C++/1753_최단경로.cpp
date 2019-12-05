#include <iostream>
#include <vector>
#include <queue>
#define  MAX  1e9+7
using namespace std;

vector<pair<int, int> >map[20001];
priority_queue<pair<int, int>>pq;
int d[20001] = { 0 };
int N, s;
void init()
{
	cin >> N;
	int M; cin >> M;
	cin >> s;
	int start, end, cost;
	while (M--)
	{
		cin >> start >> end >> cost;
		map[start].push_back(make_pair(end, cost));
	}
}

void calc()
{
	for (int i = 1; i <= N; ++i) {
		d[i] = MAX;
	}
	d[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cost > d[now])continue;
		for (auto i : map[now]) {
			int next = i.first;
			int next_cost = cost + i.second;
			if (next_cost < d[next]) {
				d[next] = next_cost;
				next_cost *= -1;
				pq.push(make_pair(next_cost, next));
			}
		}
	}
	
}

int main()
{
	init();
	calc();
	for (int i = 1; i <= N; ++i)
	{
		if (d[i] != MAX) {
			printf("%d\n", d[i]);
		}
		else {
			printf("INF\n");
		}
	}
	return 0;
}