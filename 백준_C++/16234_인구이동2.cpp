#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, L, R, result = 0;
int map[50][50];
int team_sum[2500] = { 0 };
bool ch[2500] = { 0 };
queue<pair<int, int> > team[2500];
queue<int >ulist[2500];
queue<int>kim;
inline bool this_union(int x, int y) {
	int tmp = x - y > 0 ? x - y : y - x;
	return tmp >= L && tmp <= R;
}

void view_map()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
		{
			cout <<map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j)cin >> map[i][j];
}


bool make_union()
{
	memset(ch, false, sizeof(ch));
	memset(team_sum, 0, sizeof(team_sum));
	bool move = false;
	for (int i = 0; i < N; ++i) {
		int tmpa, tmpb;
		for (int j = 0; j < N; ++j) {
			if (j - 1 >= 0 && this_union(map[i][j], map[i][j - 1])) {
				tmpa = i * N + j;
				tmpb = i * N + j - 1;
				ulist[tmpa].push(tmpb);
				ulist[tmpb].push(tmpa);
				move = true;
			}
			if (i - 1 >= 0 && this_union(map[i][j], map[i - 1][j])) {
				tmpa = i * N + j;
				tmpb = (i - 1) * N + j;
				ulist[tmpa].push(tmpb);
				ulist[tmpb].push(tmpa);
				move = true;
			}
		}
	}
	if (!move)return false;
	else {
		result++;
	}
	int i = 0, cnt = 0;
	while (i < N*N)
	{
		while (i < N * N)
		{
			if (!ch[i])break;
			else i++;
		}
		if (i >= N * N)break;
		kim.push(i);
		ch[i] = true;
		while (!kim.empty())
		{
			int index = kim.front();
			kim.pop();
			int r = index / N;
			int c = index % N;
			team[cnt].push(make_pair(r, c));
			team_sum[cnt] += map[r][c];
			while(!ulist[index].empty())
			{
				int tmp_index = ulist[index].front();
				ulist[index].pop();
				if (!ch[tmp_index])
				{
					kim.push(tmp_index);
					ch[tmp_index] = true;
				}
			}
		}
		team_sum[cnt] /= team[cnt].size();
		cnt++;
	}
	for (int i = 0; i < cnt; ++i)
	{
		int value = team_sum[i];
		while (!team[i].empty())
		{
			int r = team[i].front().first;
			int c = team[i].front().second;
			team[i].pop();
			map[r][c] = value;
		}
	}
	int qsize = 0;
	int teamcnt = 0;
	return true;
}


int main()
{
	init();
	while (make_union());
	cout << result << endl;
	return 0;
}