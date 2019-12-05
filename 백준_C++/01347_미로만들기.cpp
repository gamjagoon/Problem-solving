#include <iostream>
#include <string>
using namespace std;
char map[101][101];
//µ¿ ³² ¼­ ºÏ
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0}};
int N,m,now = 1,nr = 50,nc = 50;
string A = "";


void move(char hint)
{
	switch (hint)
	{
	case 'R':
		if(now == 3)now = 0;
		else now ++;
		break;
	case 'L':
		if(now == 0)now = 3;
		else now--;
		break;
	default:
		nr += dir[now][0];
		nc += dir[now][1];
		if(m < nr)m = nr;
		if(m < nc)m = nc;
		map[nr][nc] = '.';
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	cin>>A;
	map[nr][nc] = '.';
	for (int i = 0; i < N; ++i) move(A[i]);
	int sr,sc,er,ec;
	sr = sc = 101;
	er = ec = 0;
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			if (map[i][j] == '.') {
				if(i < sr) sr = i;
				if(i > er) er = i;
				if(j < sc)sc = j;
				if(j > ec)ec = j;
			}
		}
	}
	for (int i = sr; i <= er; ++i) {
		for(int j = sc; j <= ec;++j){
			if(map[i][j] != '.')printf("#");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}