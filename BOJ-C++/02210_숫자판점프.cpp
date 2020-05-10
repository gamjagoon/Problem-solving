#include <iostream>
using namespace std;

int dir[4][2] = {-1,0,1,0,0,-1,0,1};
int arr[5][5];
bool ch[1000000];
int res = 0;
bool inrange(int r,int c){
	return r>=0 && c>=0 && r < 5 && c < 5;
}

void dfs(int r,int c,int lv,int val){
	if(lv == 5){
		if(!ch[val]){
			res++;
			ch[val] = true;
		}
		return;
	}
	else{
		int nr,nc;
		for(int i = 0 ; i < 4; ++i){
			nr = r + dir[i][0];
			nc = c + dir[i][1];
			if(inrange(nr,nc)){
				dfs(nr,nc,lv+1,val*10+arr[nr][nc]);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0 ; i < 5;++i){
		for(int j = 0; j <5; ++j){
			cin>>arr[i][j];
		}
	}
	for(int i = 0 ; i < 5;++i){
		for(int j = 0; j <5; ++j){
			dfs(i,j,0,arr[i][j]);
		}
	}
	cout<<res;
}