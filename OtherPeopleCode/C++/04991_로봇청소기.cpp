#include<iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int MAXN = 22;
int N, M;
int dist[MAXN][MAXN];
char arr[MAXN][MAXN];
int st[MAXN*MAXN];
int adj[MAXN][MAXN];
int dp[12][1 << 12];
int cnt = 0;
const int dy[] = { -1,0,0,1 };
const int dx[] = { 0,1,-1,0 };
void bfs(int iy, int ix, int c) {
	memset(dist, 0x3f, sizeof dist);
	queue<pair<int, int>> q;

	dist[iy][ix] = 0;
	q.push({ 0, iy*M + ix });
	while (!q.empty()) {
		int y = q.front().second / M, x = q.front().second % M;
		int t = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 'x') continue;
			if (dist[ny][nx] != 0x3f3f3f3f) continue;
			if (arr[ny][nx] == '*') {
				adj[c][st[ny*M + nx]] = adj[st[ny*M + nx]][c] = t + 1;
			}
			dist[ny][nx] = t + 1;
			q.push({ t + 1, ny*M + nx });
		}
	}
}

int solve(int idx, int info) {
	if (info == (1 << cnt) - 1) return 0;
	
	int &ret = dp[idx][info];
	if (ret != -1) return ret;
	ret = 0x3f3f3f3f;

	for (int next = 0; next < cnt; next++) {
		if ((info & (1 << next)) || adj[idx][next] == 0x3f3f3f3f) continue;
		ret = min(ret, solve(next, info | (1 << next)) + adj[idx][next]);
	}
	return ret;
}

int main() {
	while (scanf("%d%d", &M, &N), !(N == 0 && M == 0)) {
		memset(st, 0, sizeof st);
		memset(adj, 0x3f, sizeof adj);
		memset(dp, -1, sizeof dp);
		cnt = 0;
		int iy, ix;
		for (int n = 0; n < N; n++) {
			scanf("%s", &arr[n]);
			for (int m = 0; m < M; m++) {
				if (arr[n][m] == 'o') iy = n, ix = m, arr[n][m] = '*', st[n*M + m] = cnt++;
				else if (arr[n][m] == '*') st[n*M + m] = cnt++;
			}
		}

		for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) {
			if (arr[n][m] == '*') bfs(n, m, st[n*M+m]);
		}

		int ans = solve(st[iy*M + ix], (1 << st[iy*M + ix]));
		printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
	}
	return 0;
}