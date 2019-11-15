#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void init();
void gamsi_1(int mode, int r, int c);
void gamsi_2(int mode, int r, int c);
void gamsi_3(int mode, int r, int c);
void gamsi_4(int mode, int r, int c);
void gamsi_5(int r, int c);
void remove_1(int mode, int r, int c);
void remove_2(int mode, int r, int c);
void remove_3(int mode, int r, int c);
void remove_4(int mode, int r, int c);
int calc_zero();
void dfs(int n);

/*동: 0 남:1 서:2 북:3*/
int dir_r[4] = { 0,1,0,-1 };
int dir_c[4] = { 1,0,-1,0 };
int map[10][10], R, C, result, cnt_cam = 0;
int gam[10][10];
vector<pair<int, pair<int, int>>>camera;
vector<pair<int, int>>camera5;
vector<int>trace;


int main() {
	init();
	for (size_t i = 0; i < camera5.size(); ++i) {
		int r = camera5[i].first;
		int c = camera5[i].second;
		gamsi_5(r, c);
	}
	result = calc_zero();
	dfs(0);
	printf("%d", result);
	return 0;
}


void init() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 6 && map[i][j] != 0 && map[i][j] != 5) {
				camera.push_back({ map[i][j],{ i,j } });
				cnt_cam++;
			}
			else if (map[i][j] == 5) {
				camera5.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i <= R + 1; ++i)map[i][0] = 6;
	for (int i = 0; i <= R + 1; ++i)map[i][C + 1] = 6;
	for (int i = 0; i <= C + 1; ++i)map[0][i] = 6;
	for (int i = 0; i <= C + 1; ++i)map[R + 1][i] = 6;
}

int calc_zero() {
	int cnt = 0;
	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			if (map[i][j] == 0)cnt++;
	return cnt;
}

void dfs(int n) {
	if (n == cnt_cam) {
		int res = calc_zero();
		result = res < result ? res : result;
		return;
	}
	else {
		int cam = camera[n].first;
		int r = camera[n].second.first;
		int c = camera[n].second.second;
		switch (cam)
		{
		case 1:
			for (int i = 0; i <= 3; ++i) {
				gamsi_1(i, r, c);
				trace.push_back(i);
				dfs(n + 1);
				trace.pop_back();
				remove_1(i, r, c);
			}
			break;
		case 2:
			for (int i = 0; i <= 1; i ++) {
				gamsi_2(i, r, c);
				trace.push_back(i);
				dfs(n + 1);
				trace.pop_back();
				remove_2(i, r, c);
			}
			break;
		case 3:
			for (int i = 0; i <= 3; ++i) {
				gamsi_3(i, r, c);
				trace.push_back(i);
				dfs(n + 1);
				trace.pop_back();
				remove_3(i, r, c);
			}
			break;
		default:
			for (int i = 0; i <= 3; ++i) {
				gamsi_4(i, r, c);
				trace.push_back(i);
				dfs(n + 1);
				trace.pop_back();
				remove_4(i, r, c);
			}
			break;
		}
	}
}

//회전 시킨다
int rotate(int dir) {
	if (dir == 3)return 0;
	else return dir + 1;
}
//공간인지 판단
bool is_blank(int r, int c) {
	return map[r][c] != 6;
}

//감시구역을 제거가능한지 검사 
//만약 기둥이 있다면 0리턴
bool remove_box(int r, int c) {
	if (map[r][c] == -1 && gam[r][c] == 1) {
		map[r][c] = 0;
		gam[r][c] = 0;
		return true;
	}
	else if (map[r][c] == -1) {
		gam[r][c]--;
		return true;
	}
	else if (map[r][c] == 6) {
		return false;
	}
	else {
		return true;
	}
}

//감시 함수들
void gamsi_1(int mode, int r, int c)
{
	while (1) {
		if (is_blank(r + dir_r[mode], c + dir_c[mode])) {
			r += dir_r[mode];
			c += dir_c[mode];
			if (map[r][c] == 0)
			{
				map[r][c] = -1;
				gam[r][c]++;
			}
			else if (map[r][c] == -1) {
				gam[r][c]++;
			}
		}
		else {
			return;
		}
	}
}

void gamsi_2(int mode, int r, int c)
{
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
}

void gamsi_3(int mode, int r, int c)
{
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
}

void gamsi_4(int mode, int r, int c)
{
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
}

void gamsi_5(int r, int c)
{
	int mode = 0;
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
	mode = rotate(mode);
	gamsi_1(mode, r, c);
}

//감시구역을 초기화 해주는 함수
void remove_1(int mode, int r, int c)
{
	while (1) {
		r += dir_r[mode];
		c += dir_c[mode];
		if (remove_box(r, c)) {
			continue;
		}
		else {
			return;
		}
	}
}
void remove_2(int mode, int r, int c)
{
	remove_1(mode, r, c);
	mode = rotate(mode);
	mode = rotate(mode);
	remove_1(mode, r, c);
}

void remove_3(int mode, int r, int c)
{
	remove_1(mode, r, c);
	mode = rotate(mode);
	remove_1(mode, r, c);
}

void remove_4(int mode, int r, int c)
{
	remove_1(mode, r, c);
	mode = rotate(mode);
	remove_1(mode, r, c);
	mode = rotate(mode);
	remove_1(mode, r, c);
}
