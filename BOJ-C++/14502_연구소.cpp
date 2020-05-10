#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dir_r[4] = { 0,0,1,-1 };
int dir_c[4] = { 1,-1,0,0 };
int map[8][8], R, C, result = 0, br_size = 0;
vector<pair<int, int>>bi;
vector<pair<int, int>>blank_room;


bool out_range(int r, int c) {
	return r < 0 || c < 0 || r >= R || c >= C;
}

bool find_wall() {
	bool ch[8][8] = { false };
	int res = 0;
	for (int i = 0; i < bi.size(); ++i) {
		int r = bi[i].first;
		int c = bi[i].second;
		for (int j = 0; j < 4; ++j) {
			int nr = r + dir_r[j];
			int nc = c + dir_c[j];
			if (out_range(nr, nc) || ch[nr][nc] == true) continue;
			if (map[nr][nc] == 0) {
				ch[nr][nc] = true;
				res++;
				if (res > 3)return false;
			}
		}
	}
	return true;
}

int move_birus() {
	bool  ch[8][8] = { false };
	queue<pair<int, int>>q;
	int res = 0;
	for (int i = 0; i < bi.size(); ++i) {
		int r = bi[i].first;
		int c = bi[i].second;
		q.push({ r,c });
		while (!q.empty())
		{
			int qr = q.front().first;
			int qc = q.front().second;
			q.pop();
			for (int j = 0; j < 4; ++j)
			{
				int nr = qr + dir_r[j];
				int nc = qc + dir_c[j];
				if (out_range(nr, nc) || ch[nr][nc] )continue;
				if (map[nr][nc] == 0) {
					ch[nr][nc] = true;
					map[nr][nc] = 2;
					q.push({ nr,nc });
					res++;
				}
			}
		}
	}
	return res;
}
//완전탐색 실시
/*
1 벽을 세운다
*/
void dfs(int r_idx, int n) {
	if (n == 3) {
		int ori_map[8][8];
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				ori_map[i][j] = map[i][j];
		int res = br_size - 3;//기둥 3개로 구역 사라짐 고려
		res -= move_birus();
		result = result < res ? res : result;
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				map[i][j] = ori_map[i][j];
		return;
	}
	if (r_idx >= br_size)return;
	else {
		int r = blank_room[r_idx].first;
		int c = blank_room[r_idx].second;
		map[r][c] = 1;
		dfs(r_idx + 1, n + 1);
		map[r][c] = 0;
		dfs(r_idx + 1, n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp == 2) {
				bi.push_back({ i,j });
			}
			else if (tmp == 0) {
				blank_room.push_back({ i,j });
				br_size++;
			}
			map[i][j] = tmp;
		}
	}
	result = br_size;
	//바이러스 주변 벽 갯수 탐색
	if (find_wall()) {
		printf("%d", result - 3);
		return 0;
	}
	result = 0;
	dfs(0, 0);
	printf("%d", result);
	return 0;
}