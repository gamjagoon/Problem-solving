#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 100
using namespace std;
 
int N, Answer;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};
vector<pair<int, int>> V;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
	Answer = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
			{
				MAP[i][j] = -1;
				V.push_back(make_pair(i, j));
			}
		}
	}
}
 
void Make_LandLabel(int a, int b, int L)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Visit[a][b] = true;
	MAP[a][b] = L;

	while (Q.empty() == 0)
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (Visit[nx][ny] == false && MAP[nx][ny] == -1)
				{
					Visit[nx][ny] = true;
					MAP[nx][ny] = L;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
 
int BFS(int Num)
{
	int Result = 0;
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] == Num)
			{
				Visit[i][j] = true;
				Q.push(make_pair(i, j));
			}
		}
	}

	while (Q.empty() == 0)
	{
		int S = Q.size();
		for (int i = 0; i < S; i++)
		{
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dir[j][0];
				int ny = y + dir[j][1];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N)
				{
					if (MAP[nx][ny] != 0 && MAP[nx][ny] != Num) return Result;
					else if (MAP[nx][ny] == 0 && Visit[nx][ny] == false)
					{
						Visit[nx][ny] = true;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}
		Result++;
	}
}
 
void Solution()
{
	int Land_Label = 1;
	for (int i = 0; i < V.size(); i++)
	{
		int x = V[i].first;
		int y = V[i].second;

		if (Visit[x][y] == false)
		{
			Make_LandLabel(x, y, Land_Label);
			Land_Label++;
		}
	}

	for (int i = 1; i < Land_Label; i++)
	{
		Answer = Min(Answer, BFS(i));
		memset(Visit, false, sizeof(Visit));
	}
	cout << Answer << endl;
}
void Solve()
{
	Input();
	Solution();
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
