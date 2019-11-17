#include <cstdio>
#include <queue>
using namespace std;
// 8 ~ 50
void init();
void color(int r,int r_e,int c,int c_e,char prev);
void dfs(int r,int c,int r_e,int c_e);
char map[50][50],orimap[50][50];
bool ch[50][50];
int R,C,result_cnt = 0,result= 100;
int dir_r[4] = {0,1};
int dir_c[4] = {1,0};

int main(){
	init();
	char prev_color = map[0][0];
	if(prev_color == 'W')prev_color = 'B';
	else prev_color = 'W';
	for(int i = 0; i <= R-8;++i){
		for(int j = 0 ; j <= C-8;++j){
			if(map[i][j] == 'W'){
				result_cnt  = 0;
				dfs(i,j,i+8,j+8);
				map[i][j] = 'B';
				result_cnt = 1;
				dfs(i,j,i+8,j+8);
				map[i][j] = 'W';
			}
			else{
				result_cnt  = 0;
				dfs(i,j,i+8,j+8);
				map[i][j] = 'W';
				result_cnt = 1;
				dfs(i,j,i+8,j+8);
				map[i][j] = 'B';
			}
		}
	}
	printf("%d",result);
	return 0;
}

bool out_range(int r,int c,int r_e,int c_e){
	return r<0 || r >= r_e || c<0 || c >= c_e;
}

void init()
{
	scanf("%d %d\n",&R,&C);
	for(int i =0 ; i<R;++i){
		int ch,j = 0;
		while( (ch = getchar()) != '\n'){
			map[i][j] = ch;
			orimap[i][j++] = ch;
		}
	}
}
// true W false B
void dfs(int r,int c,int r_e,int c_e){
	char prev_color = map[r][c];
	if(prev_color == 'W')prev_color = 'B';
	else prev_color = 'W';
	color(r,r_e,c,c_e,prev_color);
	for(int i =r ; i<r_e;++i){
		for(int j = c; j < c_e;++j){
			ch[i][j] = false;
		}
	}
	result = result_cnt < result ? result_cnt : result;
	return ;
}

void color(int r,int r_e,int c,int c_e,char prev){
	int nowchar = map[r][c];
	if(prev == 'W' &&prev == nowchar){
		result_cnt++;
		nowchar = 'B';
	}
	else if(prev == 'B' &&prev == nowchar){
		result_cnt++;
		nowchar = 'W';
	}
	ch[r][c] = true;
	for(int i = 0 ; i < 2;++i){
		int nr = r+ dir_r[i];
		int nc = c+ dir_c[i];
		if(out_range(nr,nc,r_e,c_e))continue;
		if(!ch[nr][nc])color(nr,r_e,nc,c_e,nowchar);
	}
	return;
}