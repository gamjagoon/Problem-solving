#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 9223372036854775807
using namespace std;
long long n, p, q, sum[110], dist[110][110], meet_list[110], meet_dist[110][110];
bool ch[110];
bool dupl[110];
priority_queue<pair<long long, int>>pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		memset(ch, false, sizeof(ch));
		memset(dupl, false, sizeof(dupl));
		for (int i = 0; i < 110; ++i) {
			for (int j = 0; j < 110; ++j) {
				if (i == j)dist[i][j] = 0;
				else {
					dist[i][j] = INF;
				}
			}
		}
		for (int i = 0; i < 110; ++i) sum[i] = 0;
		cin >> n >> p >> q;
		for (int i = 0; i < n; ++i) {
			cin >> meet_list[i];
			dupl[meet_list[i]] = true;
		}
		for (int j = 0; j < q; ++j) {
			long long a, b, cost;
			cin >> a >> b >> cost;
			if (cost < dist[a][b]) dist[a][b] = cost;
			if (cost < dist[b][a]) dist[b][a] = cost;
		}

		for (int i = 1; i <= p; ++i) {
			if (!dupl[i])continue;
			int now_meet = i;
			fill(&meet_dist[i][0], &meet_dist[i][109], INF);
			pq.push({ 0,now_meet });
			meet_dist[now_meet][now_meet] = 0;
			while (!pq.empty()) {
				int now = pq.top().second;
				long long cost = pq.top().first * -1;
				pq.pop();
				if (cost > meet_dist[now_meet][now]) continue;
				for (int next = 1; next <= p; ++next)
				{
					if (dist[now][next] == INF)continue;
					long long next_cost = cost + dist[now][next];
					if (meet_dist[now_meet][next] > next_cost) {
						meet_dist[now_meet][next] = next_cost;
						next_cost *= -1;
						pq.push({ next_cost,next });
					}
				}
			}
		}
		for (int i = 1; i <= p; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (meet_dist[meet_list[j]][i] == INF)
				{
					ch[i] = true;
					break;
				}
				sum[i] += meet_dist[meet_list[j]][i] * meet_dist[meet_list[j]][i];
			}
		}
		long long result = INF;
		int node = 0;
		for (int i = 1; i <= p; ++i)
		{
			if (ch[i])continue;
			if (sum[i] < result) {
				node = i;
				result = sum[i];
			}
		}
		cout<<node <<" "<<result<<'\n';
	}
}