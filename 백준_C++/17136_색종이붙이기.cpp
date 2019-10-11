#include <algorithm>
#include <cstdio>
#include <cstring>

bool arr[11][11];
int paper[6] = {-1,5,5,5,5,5};
int cnt = 0;
int result = 5;

int main(){
	for(int r = 0;r < 10;++r){
		for(int c = 0;c < 10;++c){
			scanf("%d",&arr[r][c]);
		}
	}
}
// x,y 에서 5부터 4 3 2 1의 정사각형 존재확인
bool Inspection(int x,int y,int n){
	if(arr[y + n - 1][x + n -1] != 1)return false;
	if(arr[y + n - 1][x] != 1)return false;
	if(arr[y][x + n - 1] != 1)return false;
	for(int i = y;i < y+n;++i){
		for(int j = x;j < x+n;++j){
			if(arr[i][j] != 1){
				return false;
			}
		}
	}
	return true;
}

void dfs(int x,int y){
	if(x == 10){
		dfs(0,y+1);
		return;
	}
	if(y == 10){
		result = min(result, cnt);
		return;
	}
}