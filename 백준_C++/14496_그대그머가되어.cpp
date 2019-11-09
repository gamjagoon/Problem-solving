#include <iostream>
#include <queue>
int a, b;
int N, M;
using namespace std;
int connect[1001][1001];
bool visit[1001];
typedef pair<int, int>p;
void bfs() 
{
	int start = a;
	queue<pair<int,int>>q;
	q.push(make_pair(a,0));
	visit[a] = true;
	while (!q.empty())
	{
			p tmp = q.front();
			q.pop();
			if (tmp.first == b) {
				printf("%d", tmp.second);
				return;
			}
			for (int i = 1; i <= N; ++i) {
				if (!visit[i] && connect[tmp.first][i]) {
					visit[i] = true;
					q.push(make_pair(i, tmp.second + 1));
				}
			}
	}
	printf("-1");
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int tmp0;
		int tmp1;
		cin >> tmp0 >> tmp1;
		connect[tmp0][tmp1] = 1;
		connect[tmp1][tmp0] = 1;
	}
	if (a == b) {
		printf("0");
		return 0;
	}
	bfs();

	return 0;
}