#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>

using namespace std;

typedef pair<int, int>p;
int map[53][53];
int visit[5152];
const int dir_r[4] = { 0,0,1,-1 };
const int dir_c[4] = { 1,-1,0,0 };
int n, result = 1e9;

inline int gethash(int n10, int n) {
	return n10 * 100 + n;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)scanf("%1d", &map[i][j]);
	for (int i = 1; i <= 5151; ++i) {
		visit[i] = 51;
	}
	deque<p>dq;
	dq.push_back({ 1,1 });
	visit[gethash(1, 1)] = 0;
	while (!dq.empty()) {
		int r = dq.front().first;
		int c = dq.front().second;
		int now = gethash(r, c);
		dq.pop_front();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dir_r[i];
			int nc = c + dir_c[i];
			int next = gethash(nr, nc);
			if (nr < 1 || nr > n || nc < 1|| nc > n)continue;
			int cost;
			if (map[nr][nc] == 0) {
				cost = 1;
			}
			else cost = 0;
			if (visit[next] > visit[now] + cost) {
				visit[next] = visit[now] + cost;
				//cost 1 map = 0 push back 
				//cost 0 map = 1 push front
				if (cost == 1)dq.push_back({ nr,nc });
				else dq.push_front({ nr,nc });
			}
		}
	}
	printf("%d", visit[gethash(n,n)]);
	return 0;
}
