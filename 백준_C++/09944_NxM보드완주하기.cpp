#include<iostream>
#include<cstring>
#include<queue>
#define endl "\n"
using namespace std;
 
int N, M;
int blank;
int ans;
char arr[31][31];
bool ch[31][31];
queue<pair<int, int>> start_point;
 
int dir[4][2]={1,0,-1,0,0,1,0,-1};

inline bool out_range(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return true;
	return false;
}
 
void doit(int x, int y, int d, int Cnt, int result)
{
	if (Cnt == blank)
	{
		if (ans > result) ans = result;
		return;
	}

	int nx = x + dir[d][0];
	int ny = y + dir[d][1];

	if (out_range(nx, ny) == false && ch[nx][ny] == false && arr[nx][ny] == '.')
	{
		ch[nx][ny] = true;
		doit(nx, ny, d, Cnt + 1, result);
		ch[nx][ny] = false;
	}
	else
	{
		for (int nd = 0; nd < 4; nd++)
		{
			if (nd == d) continue;
			nx = x + dir[nd][0];
			ny = y + dir[nd][1];
			
			if (out_range(nx, ny) == false && ch[nx][ny] == false && arr[nx][ny] == '.')
			{
				ch[nx][ny] = true;
				doit(nx, ny, nd, Cnt + 1, result + 1);
				ch[nx][ny] = false;
			}
		}
	}    
}
 
void Solution()
{
	if (blank == 1)
	{
		ans = 0;
		return;
	}
	while(!start_point.empty())
	{
		int x = start_point.front().first;
		int y = start_point.front().second;
		start_point.pop();
		for (int d = 0; d < 4; d++)
		{
			ch[x][y] = true;
			doit(x, y, d, 1, 1);
			ch[x][y] = false;
		}
	}
}
 
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while (cin >> N >> M)
	{
		memset(ch, false, sizeof(ch));
		memset(arr, 0, sizeof(arr));
		blank = 0;
		ans = INT32_MAX;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '.')
				{
					start_point.push({i, j});
					blank++;
				}
			}
		}
		Solution();
		if (ans == INT32_MAX) ans = -1;
		cout << "Case " << t << ": " << ans << endl;
		t++;
	}
	return 0;
}
