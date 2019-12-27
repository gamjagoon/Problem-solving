#include <iostream>
#include <queue>
using namespace std;

int R, C;
unsigned char map[1002][1002];
int tmp;
int cnt = 0;
queue<pair<int, int>> q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//1 익은토마토 0 익지 않은거 -1 빈칸
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> R;
	for (int i = 0; i < R;++i)
	{
		for (int j = 0; j < C;++j)
		{
			cin >> tmp;
			if(tmp == 0)
			{
				map[i][j] = 0;
				cnt++;
			}
			else if(tmp == 1)
			{
				map[i][j] = 1;
				q.push(make_pair(i, j));
			}
			else
			{
				map[i][j] = 2;
			}
		}
	}
}

int bfs()
{
	int time = 0;
	if(cnt == 0)
		return 0;
	while(!q.empty())
	{
		time++;
		int t = q.size();
		for (int i = 0; i < t; ++i)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int j = 0; j < 4;++j)
			{
				int nr = r + dir[j][0];
				int nc = c + dir[j][1];
				if(nr < 0 || nc < 0|| nr >= R || nc >= C)
					continue;
				if(map[nr][nc] == 0)
				{
					map[nr][nc] = 1;
					q.push(make_pair(nr, nc));
					cnt--;
				}
			}
		}
		if(cnt == 0)break;
	}
	if(cnt == 0)
		return time;
	else
		return -1;
}

int main()
{
	input();
	cout << bfs();
	return 0;
}