#include <iostream>
#include <cstring>
//Ž������
// 2<= C <= N-1;
// 0<= R <= N-2;
using namespace std;
int N, result = 1e9, all_sum = 0;
int map[21][21];

void calc(int R, int C)
{
	int sum_team[5];
	
	for(int D1 = 1;D1 <= N;++D1)
	{
		for(int D2 = 1;D2<= N;++D2)
		{
			if (R + D2 + D1 > N || C + D2 > N || C - D1 <= 0)break;
			memset(sum_team, 0, sizeof(sum_team));
			int x = 1;
			for (int r = 1; r < R; ++r) {
				for (int c = 1; c <= C; ++c){
					sum_team[0] += map[r][c];
				}
			}
			for (int r = R; r < R + D1; ++r) {
				for (int c = 1; c <= C - x; ++c) {
					sum_team[0] += map[r][c];
				}
				x++;
			}
			x = 0;
			for (int r = 1; r < R; ++r) {
				for (int c = C + 1; c <= N; ++c) {
					sum_team[1] += map[r][c];
				}
			}
			for (int r = R ; r <= R + D2; ++r) {
				for (int c = C +1+ x; c <= N; ++c) {
					sum_team[1] += map[r][c];
				}
				x++;
			}
			x = 0;
			for (int r = R + D1 + D2; r >= R + D1; --r) {
				for (int c = 0; c < C - D1+D2- x; ++c) {
					sum_team[2] += map[r][c];
				}
				x++;
			}
			for (int r = R + D2+D1+1; r <= N; ++r) {
				for (int c = 0; c < C - D1 + D2; ++c) {
					sum_team[2] += map[r][c];
				}
			}
			x = 0;
			for (int r = R + D1 + D2; r > R + D2; --r) {
				for (int c = C+D2-D1+1+x; c <= N; ++c) {
					sum_team[3] += map[r][c];
				}
				x++;
			}
			for (int r = R + D2+D1+1; r <= N; ++r) {
				for (int c = C - D1 + D2; c <= N; ++c) {
					sum_team[3] += map[r][c];
				}
			}
			sum_team[4] = all_sum - (sum_team[0] + sum_team[1] + sum_team[2] + sum_team[3]);
			int Max = sum_team[0], Min = sum_team[0];
			for (int i = 1; i < 5; ++i) {
				if (Max < sum_team[i]) {
					Max = sum_team[i];
				}
				else if(Min > sum_team[i]) {
					Min = sum_team[i];
				}
			}
			int res = Max - Min;
			result = result < res ? result : res;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
			all_sum += map[i][j];
		}
	}
	for (int r = 1; r <= N - 2; ++r) {
		for (int c = 2; c <= N - 1; ++c) {
			calc(r, c);
		}
	}
	printf("%d", result);
}
