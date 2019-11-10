#include <iostream>
//#include<vector>
using namespace std;
int arr[11][11];
bool visit[12][12];
int N, result = 1e9, now_cost = 0;
int dir_r[4] = { 0,0,1,-1 };
int dir_c[4] = { 1,-1,0,0 };
//vector<pair<int, int>> p;

inline bool out(int r, int c) {
	if (r < 2 || c < 2 || r >= N || c >= N) {
		return true;
		//printf("out range %d %d\n", r, c);
	}
	if (visit[r][c] == true)
	{
		return true;
		//printf("visited %d %d\n", r, c);
	}
	for (int i = 0; i < 4; ++i) {
		if (visit[r + dir_r[i]][c + dir_c[i]] == true) {
			//printf("outof range %d %d\n", r, c);
			return true;
		}
	}
	return false;
}

inline void onflower(int r, int c) {
	visit[r][c] = true;
	now_cost += arr[r][c];
	for (int i = 0; i < 4; ++i) {
		int nr = r + dir_r[i];
		int nc = c + dir_c[i];
		visit[nr][nc] = true;
		now_cost += arr[nr][nc];
	}
}

inline void off_flower(int r, int c) {
	visit[r][c] = false;
	now_cost -= arr[r][c];
	for (int i = 0; i < 4; ++i) {
		int nr = r + dir_r[i];
		int nc = c + dir_c[i];
		visit[nr][nc] = false;
		now_cost -= arr[nr][nc];
	}
}
void  dfs(int c, int r, int n) {
	if (n == 3) {
		//printf("cost : %d ", now_cost);
		//for (auto  k : p) {
		//	cout <<"R, C ("<<k.first<<","<<k.second<<") ";
		//}
		//cout << "\n";
		result = result < now_cost ? result : now_cost;
		return;
	}
	if (c >= N  && r >= N )return;
	if (out(r,c)) {
		if (c >= N)dfs(2, r + 1, n);
		else dfs(c + 1, r, n);
	}
	else {
		onflower(r, c);
		//p.push_back({ r,c });
		dfs(c + 2, r, n + 1);
		off_flower(r, c);
		//p.pop_back();
		dfs(c + 1, r, n);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}
	dfs(2, 2, 0);
	printf("%d", result);
}