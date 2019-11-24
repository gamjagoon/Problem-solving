#include <iostream>
#include <queue>

using namespace std;

int N, map[50][50];
queue<pair <int, int> >q;
typedef pair<int, int> p;
int dir_one[3][2] = { {1,0},{0,1},{0,-1} };
int result = 1000;
void init()
{
	cin >> N;
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j)cin >> map[i][j];
	for (int i = 0; i < N; ++i) {
		if (map[0][i] == 0) {
			p x;
			map[0][i] = -1;
			x.first = 0; x.second = i;
			q.push(x);
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		if (now.second == N - 1) {
			int tmp = map[now.first][now.second] * -1;
			result = tmp < result ? tmp : result;
		}
		for (int j = 0; j < 3; ++j) {
			int nr = now.first + dir_one[j][0];
			int nc = now.second + dir_one[j][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N )continue;
			if (map[nr][nc] == 0)
			{
				map[nr][nc] = map[now.first][now.second] - 1;
				q.push(make_pair(nr, nc));
			}
		}
	}
}
void view_map()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	init();
	view_map();
	bfs();
	view_map();
	if (result == 1000) {
		cout << "-1" << endl;
	}
	else {
		cout << result << endl;
	}
	return 0;
}