#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int R, C, H, time = 0, zero = 0;
int arr[101][101][101];
bool visit[101][101][101];
int dir_r[4] = { 0,0,1,-1 };
int dir_c[4] = { 1,-1,0,0 };

// h r c
queue<pair <int, p>>q;
//-1일때 빈공간 0이 안익은거 1이 익은거
void bfs()
{
	while (!q.empty())
	{
		if (zero <= 0)break;
		int qsize = q.size();
		for (int i = 0; i < qsize; ++i) {
			p poped = q.front().second;
			int htmp = q.front().first;
			q.pop();
			for (int j = 0; j < 4; ++j)
			{
				int r = poped.first + dir_r[j];
				int c = poped.second + dir_c[j];
				if (0 < r && r <= R && 0 < c && c <= C && arr[htmp][r][c] == 0)
				{
					arr[htmp][r][c] = 1;
					zero--;
					q.push(make_pair(htmp, make_pair(r, c)));
				}
			}
			int r = poped.first;
			int c = poped.second;
			if (htmp - 1 > 0 && arr[htmp - 1][r][c] == 0) {
				arr[htmp - 1][r][c] = 1;
				zero--;
				q.push(make_pair(htmp - 1, make_pair(r, c)));
			}
			if (htmp + 1 <= H && arr[htmp + 1][r][c] == 0) {
				arr[htmp + 1][r][c] = 1;
				zero--;
				q.push(make_pair(htmp + 1, make_pair(r, c)));
			}
		}
		time++;
	}
	if (zero <= 0)time;
	else time = -1;
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> R >> H;
	for (int h = 1; h <= H; ++h) {
		for (int r = 1; r <= R; ++r) {
			for (int c = 1; c <= C; ++c) {
				cin >> arr[h][r][c];
				if (arr[h][r][c] == 1) {
					p tmp;
					tmp.first = r;
					tmp.second = c;
					q.push(make_pair(h, tmp));
				}
				else if (arr[h][r][c] == 0) {
					zero++;
				}
			}
		}
	}
	if (zero == 0)printf("0");
	else {
		bfs();
		printf("%d", time);
	}
	return 0;
}