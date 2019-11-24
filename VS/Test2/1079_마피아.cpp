#include <iostream>
#include <queue>
using namespace std;

int N, score[16], R[16][16];
int me, live_cnt =0, result = 0;
bool dead[16] = { 0 };
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> score[i];
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> R[i][j];
		}
	}
	cin >> me;
	live_cnt = N;
}
void initial_dead() {
	for (int i = 0; i < N; ++i) {
		dead[i] = false;
	}
}
int calc()
{
	int idx = -1;
	int max = -1;
	for (int i = 0; i < N; ++i) {
		if (score[i] > max && !dead[i]) {
			idx = i;
			max = score[i];
		}
	}
	return idx;
}
bool end_game = false;
void dfs(int night)
{
	if (end_game)return;
	if (dead[me] || live_cnt == 1) {
		if (live_cnt % 2)night += 1;
		if (night > result || result == -1)result = night;
		if (live_cnt == 1)end_game = true;
		return;
	}
	if (live_cnt % 2 == 0) {
		for (int i = 0; i < N; ++i)
		{
			if (end_game)return;
			if (!dead[i] && i != me)
			{
				queue<int>q;
				for (int j = 0; j < N; ++j) {
					score[j] += R[i][j];
					q.push(R[i][j]);
				}
				dead[i] = true; live_cnt--;
				dfs(night);
				dead[i] = false; live_cnt++;
				for (int j = 0; j < N; ++j) {
					score[j] -= q.front();
					q.pop();
				}
			}
		}
	}
	//morning
	else {
		int number = calc();
		dead[number] = true; live_cnt--;
		dfs(night + 1);
		dead[number] = false;live_cnt++;
	}
}
int main()
{
	init();
	initial_dead();
	if (N == 1) result = 0;
	else
	{
		if (N % 2) dfs(-1);
		else dfs(0);
	}
	cout << result;
	return 0;
}