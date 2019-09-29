#include <iostream>
#include <algorithm>
using namespace std;


int cnt = 0;
int N;
int arr[18][18] = {};
int DFS(int iy,int ix,int sig){
	if(ix == N-1 && iy == N-1){
    	return 1;
	}
	if(ix > N || iy > N){
		return 0;
	}
	if(sig == 0){
		if(arr[iy][ix+1]==0 &&arr[iy+1][ix+1]==0 &&arr[iy+1][ix]==0){
			return DFS(iy+1,ix+1,2)+DFS(iy,ix+1,0);
		}
		if(arr[iy][ix+1]==0){
			return DFS(iy,ix+1,0);
		}
		return 0;
	}
	if(sig == 1){
		if(arr[iy][ix+1]==0 &&arr[iy+1][ix+1]==0 &&arr[iy+1][ix]==0){
			return DFS(iy+1,ix+1,2)+DFS(iy+1,ix,1);
		}
		if(arr[iy+1][ix]==0){
			return DFS(iy+1,ix,1);
		}
		return 0;
	}
	if(sig == 2){
		if(arr[iy][ix+1]==0){
			if(arr[iy+1][ix+1]==0 && arr[iy+1][ix]==0){
				return DFS(iy+1,ix+1,2)+DFS(iy,ix+1,0)+DFS(iy+1,ix,1);
			}
			if(arr[iy+1][ix]==0){
				return DFS(iy+1,ix,1)+DFS(iy,ix+1,0);
			}
			return DFS(iy,ix+1,0);
		}
		if(arr[iy+1][ix]==0){
			return DFS(iy+1,ix,1);
		}
		return 0;
	}
	return 0;
}

int main(){
	cin>>N;
	for(int i = 0 ; i < N;++i){
		for(int j = 0 ; j < N;++j){
			cin>>arr[i][j];
		}
	}
	for(int i = 0 ; i < N;++i){
		arr[i][N] = 1;
		arr[i][N+1] = 1;
	}
	for(int i = 0 ; i <= N;++i){
		arr[N][i] = 1;
		arr[N+1][i] = 1;
	}
    cout<<DFS(0,1,0);
}