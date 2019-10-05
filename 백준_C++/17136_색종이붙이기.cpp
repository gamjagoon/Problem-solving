#include <iostream>
#include <cstdio>

using namespace std;

int arr[10][10]; //변결할것
int index = 1;
int result = 0;
int cnt[6] = {-1,5,5,5,5,5};
int parent[10][10];
int count[101];

void display();
void make_union(const int y,const int x);
void calc_rec();
bool remove_rec(const int u,const int n);
bool view_cnt();

int main(){
	for(int y = 0;y < 10;++y){
		for(int x = 0;x< 10;++x){
			scanf("%d",&arr[y][x]);
			if(arr[y][x] == 1)make_union(y,x);
		}
	}
	calc_rec();
	if(!view_cnt())return 0;
	display();
	int cntcpy[6] = {-1,cnt[1],cnt[2],cnt[3],cnt[4],cnt[5]};

}

void display(){
	printf("========================================\n");
	for(int i = 0;i < 10;++i){
		for(int j = 0;j< 10;++j){
			printf("%2d ",parent[i][j]);
		}
		printf("\n");
	}
}
/*
[y-1][x] -> [y][x-1] 순서로 탐색한다
*/
void make_union(const int y,const int x){
	int key = index;
	if(y-1>=0 && parent[y-1][x] != 0){
		if(key > parent[y-1][x]){
			key = parent[y-1][x];
		}
		else{
			parent[y-1][x] = key;
		}
	}
	if(x-1>= 0 && parent[y][x-1] != 0){
		if(key > parent[y][x-1]){
			key = parent[y][x-1];
		}else{
			parent[y][x-1] = key;
		}
	}
	parent[y][x] = key;
	arr[y][x] = key;
	count[key]++;
	index++;
}

void calc_rec(){
	for(int i = 0 ; i < index;++i){
		int n = count[i];
		if(n == 0)continue;
		switch(n){
			case 1:
			if(remove_rec(i,1)){
				count[i] = 0;
			}
			continue;
			case 4:
			if(remove_rec(i,2)){
				count[i] = 0;
			}
			continue;
			case 9:
			if(remove_rec(i,9)){
				count[i] = 0;
			}
			continue;
			case 16:
			if(remove_rec(i,4)){
				count[i] = 0;
			}
			continue;
			case 25:
			if(remove_rec(i,5)){
				count[i] = 0;
			}
			continue;
			default:
			continue;
		}
	}
}

bool remove_rec(const int u,const int n){
	int idx,idy;
	bool find = false;
	for(int i = 0 ; i < 10;++i){
		for(int j = 0 ; j < 10;++j){
			if(parent[i][j] == u){
				idx = j;
				idy = i;
				find = true;
				break;
			}
		}
		if(find == true)break;
	}
	if(parent[idy + n - 1][idx + n -1] != u)return false;
	if(parent[idy + n - 1][idx] != u)return false;
	if(parent[idy][idx + n - 1] != u)return false;
	for(int i = idy;i < idy+n;++i){
		for(int j = idx;j < idx+n;++j){
			if(parent[i][j] != u){
				return false;
			}
		}
	}
	for(int i = idy;i < idy+n;++i){
		for(int j = idx;j < idx+n;++j){
			arr[i][j] = 0;
			parent[i][j] = 0;
		}
	}
	cnt[n]-=1;
	return true;
}

bool view_cnt(){
	for(int i = 1;i < 6 ; ++i){
		if(cnt[i] < 0 ){
			printf("-1");
			return false;
		}
	}
	return true;
}
