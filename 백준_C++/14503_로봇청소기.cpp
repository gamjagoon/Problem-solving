#include <iostream>
#include <cstdio>
using namespace std;

void init();
void view_map();
void rotate();
void clean();
bool back();
bool loc();


/*북:0 동:1 남:2 서:3*/
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };
int map[50][50];
int R, C, result_cnt = 0, dir, r, c;


int main()
{
	init();
	//view_map();
	while (1) {
		//왼쪽에 청소 했거나 벽이면 회전
		//4번 회전했다면 뒤에 벽이 아니라면 후진
		//벽이라면 종료
		if (map[r][c] == 0) {
			map[r][c] = -1;
			result_cnt++;
		}
		if (loc()) {
			clean();
		}
		else if(!back()) {
			break;
		}
	}
	printf("%d\n", result_cnt);
	return 0;
}


void view_map()
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			printf("%2d ", map[i][j]);
		printf("\n");
	}
}

void init() {
	scanf("%d %d", &R, &C);
	scanf("%d %d %d", &r, &c, &dir);
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			scanf("%d", &map[i][j]);
}

void rotate()
{
	if (dir == 0)dir = 3;
	else dir--;
}

void clean() 
{
	//미리 회전
	rotate();
	int nr = r + dir_r[dir];
	int nc = c + dir_c[dir];
	if (map[nr][nc] == 0) {
		r = nr; c = nc;
	}
	return;
}

bool loc()
{
	for (int i = 0; i <= 3; ++i) {
		if (map[r + dir_r[i]][c + dir_c[i]] == 0) {
			return true;
		}
	}
	
	return false;
}

bool back()
{
	int br = r - dir_r[dir];
	int bc = c - dir_c[dir];
	if (map[br][bc] != 1) {
		r = br;
		c = bc;
		return true;
	}
	else {
		return false;
	}
}