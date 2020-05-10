#include <algorithm>
#include <cstdio>
#include <cstring>

bool arr[10][10];
int paper[6] = {-1,5,5,5,5,5};
int cnt = 0;
int result = 26;

void dfs(int x,int y);
bool Inspection(int x,int y,int n);

int main(){
	for(int r = 0;r < 10;++r){
		for(int c = 0;c < 10;++c){
			scanf("%d",&arr[r][c]);
		}
	}
	dfs(0,0);
	if(result == 26){
		printf("-1");
	}
	else{
		printf("%d",result);
	}
	return 0;
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
	if(x >= 10){
		dfs(0,y+1);
		return;
	}
	if(y >= 10){
		result = std::min(result, cnt);
		return;
	}
	if(arr[y][x] == 0){
		dfs(x+1,y);
		return;
	}
	for(int n = 5;n >=1;--n){
		if(paper[n] == 0||y+n > 10||x+n > 10)continue;
		if(!Inspection(x,y,n))continue;
		for(int r = y; r < y+n;++r){
			for(int c = x; c < x+n;++c){
				arr[r][c] = 0;
			}
		}
		paper[n]--;
		cnt++;
		dfs(x+n,y);
		for(int r = y; r < y+n;++r){
			for(int c = x; c < x+n;++c){
				arr[r][c] = 1;
			}
		}
		paper[n]++;
		cnt--;
	}
}