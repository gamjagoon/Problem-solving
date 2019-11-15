#include <iostream>
using namespace std;
int N, M, r, c, K, dir,key;
int arr[23][23];
int dir_r[5] = { -1,0,0,-1,1 };
int dir_c[5] = { -1,1,-1,0,0 };
/*
dice[1] = 困 dice[2] = 合 dice[4] = 辑  dice[3] = 悼 dice[5] = 巢 dice[6] = 顶
*/
int dice[7] = { 0,0,0,0,0,0,0 };
//1悼率 2 辑率 3 合率 4巢率


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> r >> c >> K;
	r++; c++;
	for (int i = 0; i <= N + 1; ++i)arr[0][i] = -1;
	for (int i = 0; i <= N + 1; ++i)arr[N + 1][i] = -1;
	for (int i = 0; i <= M + 1; ++i)arr[i][0] = -1;
	for (int i = 0; i <= M + 1; ++i)arr[i][M + 1] = -1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		cin >> dir;
		int nr = r + dir_r[dir];
		int nc = c + dir_c[dir];
		int loc = arr[nr][nc];
		if (loc == -1) continue;
		if (dir == 1) {
			key = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = key;
		}
		if (dir == 2)
		{
			key = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = key;
		}
		if (dir == 3)
		{
			key = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = key;
		}
		if (dir== 4)
		{
			key = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = key;
		}
		if (loc== 0) {
			arr[nr][nc] = dice[6];
		}
		else {
			dice[6] = loc;
			arr[nr][nc] = 0;
		}
		printf("%d\n", dice[1]);
		r = nr;
		c = nc;
	}
}