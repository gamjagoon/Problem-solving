#include <cstdio>

#include <queue>
using namespace std;
char map[51][51];
int R, C, start_x, start_y,result = 300;
queue<pair<int, int>>W;//x,y
pair<int, int>start;
int dir_x[4] = {-1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };
int turn = 1;
void init();

void flood()
{
	int m = W.size();
	for(int j = 0 ; j < m;++j)
	{
		int ox = W.front().first;
		int oy = W.front().second;
		W.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = ox+ dir_x[i];
			int y = oy + dir_y[i];
			if (1 <= x && x <= C && 1 <= y && y <= R && map[y][x]!='D'&&map[y][x]!='X'&&map[y][x] != '*') {
				map[y][x] = '*';
				W.push(make_pair(x, y));
			}
			else {
				continue;
			}
		}
	}
	printf("W size %d\n", W.size());
}
bool goal= false;
void bfs()
{
	queue<pair<int, int>>q;
	q.push(start);
	while (!q.empty())
	{
		if (goal)break;
		flood();
		int m = q.size();
		printf("q size %d\n", q.size());
		for(int j = 0;j < m;++j)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir_x[i];
				int ny = y + dir_y[i];
				if(1<= nx && nx<=C && 1<= ny && ny<= R)
				{
					if (map[ny][nx] == '.') {
						q.push(make_pair(nx, ny));
						map[ny][nx] = 'S';
					}
					else if (map[ny][nx] == 'D') {
						result = result < turn ? result : turn;
						goal = true;
						return;
					}
					else {
						continue;
					}
				}
			}
		}
		turn++;
	}
	return;
}


int main()
{
	init();
	bfs();
	if (result == 300)printf("KAKTUS");
	else printf("%d", result);
	return 0;
}

void init()
{
	scanf("%d %d\n", &R, &C);
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			char ch;
			scanf("%c", &ch);
			if (ch == 'D') {
				map[i][j] = 'D';
			}
			else if (ch == '*') {
				W.push(make_pair(j, i));
				map[i][j] = '*';
			}
			else if (ch == 'X') {
				map[i][j] = 'X';
			}
			else if (ch == 'S') {
				start.first = j;
				start.second = i;
				map[i][j] = 'S';
			}
			else {
				map[i][j] = '.';
			}
		}
		getchar();
	}
}
