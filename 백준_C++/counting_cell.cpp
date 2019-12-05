#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, map[30][30];
int color = 2;
int dir[8][2] = { {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
int color_cnt[10];
int color_fixel(int r,int c)
{
	if (r < 0 || c < 0 || r >= N || c >= N)return 0;
	else if (map[r][c] != 1)return 0;
	else {
		map[r][c] = color;
		int tmp = 1;
		for (int i = 0; i < 8; ++i) {
			tmp += color_fixel(r + dir[i][0], c + dir[i][1]);
		}
		return tmp;
	}
}

int main()
{
	// map 초기화
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	//색칠하기
	memset(color_cnt, 0, sizeof(color_cnt));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int result = 0;
			result = color_fixel(i, j);
			if (result == 0)continue;
			else {
				color_cnt[color] = result;
				color++;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < N; ++i) {
		cout <<'['<< i << ':' << color_cnt[i] << "] ";
	}
	return 0;
}