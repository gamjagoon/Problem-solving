#include <iostream>
#include <queue>
using namespace std;

int R, C;
int dir_r[4] = { 0,1,0,-1 };
int dir_c[4] = { 1,0,-1,0 };
bool map[100][100] = { 0 };
int r = 0, c = 0;
int main() {
	cin >> R >> C;
	map[r][c] = 1;
	int result = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(r, c));
	int prev_dir = 0, dir = 0;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dir_r[dir];
			int nc = c + dir_c[dir];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc])
			{
				dir++;
				if (dir == 4)dir = 0;
				continue;
			}
			map[nr][nc] = true;
			if (dir != prev_dir) {
				result++;
				prev_dir = dir;
			}
			q.push(make_pair(nr, nc));
			break;
		}
	}
	cout << result;
	return 0;
}