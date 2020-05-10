#include <stdio.h>
#include <queue>
using namespace std;
bool Maze[102][102];
int arr[101][101];
int R, C, level = 1;
int dir_x[4] = { 0,1,-1,0 };
int dir_y[4] = { 1,0,0,-1 };
typedef struct P {
	int r, c;
}p;

void view()
{
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			printf("%d ", Maze[i][j]);
		}
		printf("\n");
	}
}


void bfs() {
	queue<p>q;
	p pos;
	pos.r = 1;
	pos.c = 1;
	q.push(pos);
	Maze[1][1] = 0;
	arr[1][1] = 1;
	while(!q.empty())
	{
		int qsize = q.size();
		for(int i = 0; i < qsize;++i)
		{
			pos = q.front();
			q.pop();
			if (pos.r < 1 || pos.r > R ||pos.c > C || pos.c < 1)continue;
			for (int i = 0; i < 4; ++i) {
				int r = pos.r + dir_y[i];
				int c = pos.c + dir_x[i];
				if (r == R && c == C) {
					printf("%d", arr[pos.r][pos.c] + 1);
					return;
				}
				else if (Maze[r][c] && arr[r][c] == 0) {
					p n_pos;
					n_pos.r = r;
					n_pos.c = c;
					arr[r][c] = arr[pos.r][pos.c] + 1;
					q.push(n_pos);
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d\n", &R, &C);
	for (int r = 1; r <= R; ++r) {
		int ch, i = 1;
		while ((ch = getchar()) != '\n') {
			Maze[r][i++] = ch-'0';
		}
	}
	bfs();
	return 0;
}