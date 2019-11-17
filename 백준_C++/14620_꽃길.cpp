#include<stdio.h>
int map[11][11], chk[11][11];
int n, anw;
void back(int seed, int cost) {
	int i,j;
	if (seed == 3) {
		if (anw > cost) {
			anw = cost;
		}
		return;
	}
	for (i = 1; i < n - 1; i++) {
		for (j = 1; j < n - 1; j++) {
			if (chk[i][j] == 0 && chk[i - 1][j] == 0 && chk[i][j - 1] == 0 && chk[i][j + 1] == 0 && chk[i + 1][j] == 0) {
				chk[i][j] = 1; 
				chk[i - 1][j] = 1; 
				chk[i][j - 1] = 1; 
				chk[i + 1][j] = 1; 
				chk[i][j + 1] = 1;
				back(seed + 1, cost + map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i + 1][j] + map[i][j + 1]);
				chk[i][j] = 0; 
				chk[i - 1][j] = 0; 
				chk[i][j - 1] = 0; 
				chk[i + 1][j] = 0;
				chk[i][j + 1] = 0;
			}
		}
	}
}
int main(void) {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			anw += map[i][j];
		}
	}
	back(0, 0);
	printf("%d\n", anw);
}