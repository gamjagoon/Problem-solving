#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

//N 멥의 넓이 K는 사과의 갯수 L 방향전환
int N, K, L, dir = 0, time = 1;
int map[102][102];
char handle[10001];
int dir_r[4] = {0,1,0,-1};
int dir_c[4] = {1,0,-1,0};
queue<pair<int, int>>q;

void handle_dir(char C) {
	if (C == 'L') {//왼쪽
		if (dir == 0)dir = 3;
		else dir -= 1;
	}
	else if(C == 'D') {//오른쪽
		if (dir == 3)dir = 0;
		else dir += 1;
	}
	else {
		return;
	}
}

void go(int r, int c)
{
	if (map[r][c] == -1) {
		return;
	}
	else if(map[r][c] == 1){
		//printf("eat %d %d\n", r, c);
		handle_dir(handle[time]);
		time++;
		map[r][c] = -1;
		q.push({ r,c });
		go(r + dir_r[dir], c + dir_c[dir]);
	}
	else {
		//printf("move %d %d %d\n",r,c,map[r][c]);
		handle_dir(handle[time]);
		time++;
		map[r][c] = -1; //머리 이동
		int pr = q.front().first;
		int pc = q.front().second;
		q.pop();
		map[pr][pc] = 0;//꼬리이동
		q.push({ r,c });//머리 위치 추가
		go(r + dir_r[dir], c + dir_c[dir]);
	}
}

int main() {
	scanf("%d\n%d", &N, &K);
	for (int i = 0; i <= N + 1; ++i)map[0][i] = -1;
	for (int i = 0; i <= N + 1; ++i)map[i][0] = -1;
	for (int i = 0; i <= N + 1; ++i)map[N+1][i] = -1;
	for (int i = 0; i <= N + 1; ++i)map[i][N+1] = -1;
	int p, s;
	for (int i = 0; i < K; ++i) {
		scanf("%d %d", &p, &s);
		map[p][s] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; ++i) {
		scanf("%d %c", &p, &s);
		handle[p] = s;
	}
	map[1][1] = -1;
	q.push({ 1,1 });
	go(1+dir_r[dir], 1+dir_c[dir]);
	printf("%d", time);
	return 0;
}
