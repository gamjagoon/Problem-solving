#include <iostream>
#include <vector>
using namespace std;
int R, C;
vector<pair<int, int>>s;
vector<pair<int, int>>w;
char map[501][501];
int dir_r[4] = { 0,-1,0,1 };
int dir_c[4] = { 1,0,-1,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') s.push_back({ i,j });
			}
		}
	for (int i = 0; i < s.size(); ++i) {
		int r = s[i].first;
		int c = s[i].second;
		for (int j = 0; j < 4; ++j) {
			int nr = r + dir_r[j];
			int nc = c + dir_c[j];
			if (nr <= R && nc <= C && map[nr][nc] == 'W') {
				printf("0");
				return 0;
			}
		}
	}
	printf("1\n");
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (map[i][j] == '.') {
				printf("D");
			}
			else {
				printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}