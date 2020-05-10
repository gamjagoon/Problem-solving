#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int map[51][51];
int R, C;
int visit[51][51];
int dir_r[4] = { 0,0,1,-1 };
int dir_c[4] = { 1,-1,0,0 };
bool findunion(int gr, int gc) {
	int now = map[gr][gc];
	queue<pair<int, int>>q;
	q.push({ gr,gc });
	visit[gr][gc] = 1;
	int round = 1;
	while(!q.empty())
	{
		int qsize = q.size();
		for(int j = 0; j < qsize;++j)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dir_r[i];
				int nc = c + dir_c[i];
				if (round >= 2 && map[nr][nc] == now &&visit[nr][nc] == round+1)return true;
				if (nr > 0 && nc > 0 && nr <= R && nc <= C && map[nr][nc] == now && !visit[nr][nc]) {
					visit[nr][nc] = visit[r][c] +1;
					q.push({ nr,nc });
				}
			}
		}
		round++;
	}
	return false;
}
int main() {

	scanf("%d %d\n", &R, &C);
	for (int i = 1; i <= R; ++i) {
		int ch, j = 1;
		while ((ch = getchar()) != '\n') {
			map[i][j++] = ch;//A = 0 Z = 25
		}
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (findunion(i, j)) {
				printf("Yes");
				return 0;
			}
			for (int i = 1; i <= R; ++i) {
				for (int j = 1; j <= C; ++j) {
					visit[i][j] = 0;
				}
			}
		}
	}
	printf("No");
	return 0;
}