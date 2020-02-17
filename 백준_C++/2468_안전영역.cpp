/*
Date : 02/09/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2468
summary : bfs + dfs
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int N,arr[100][100];
bool ch[100][100];
int dir_r[4] = {1, 0 , -1, 0};
int dir_c[4] = {0, -1, 0, 1};
int res = 1,Start = 100,End = 0;

bool Out_range(int r,int c){
	if(r < 0 || c < 0 || c >= N || r >= N)return true;
	return false;
}

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i,0,N-1){
		mfor(j,0,N-1){
			cin>>arr[i][j];
			Start = Start > arr[i][j] ? arr[i][j] : Start;
			End = End > arr[i][j] ? End : arr[i][j];
		}
	}
}

void reset_ch(){
	mfor(r,0,N-1){
		mfor(c,0,N-1){
			ch[r][c] = false;
		}
	}
}

void dfs(int r,int c,int n){
	int nr,nc;
	mfor(d,0,3){
		nr = r + dir_r[d];
		nc = c + dir_c[d];
		if(!Out_range(nr,nc) && !ch[nr][nc] && arr[nr][nc] - n > 0){
			ch[nr][nc] = true;
			dfs(nr,nc,n);
		}
	}
}

int cal_live(int n){
	int res = 0;
	reset_ch();
	mfor(r,0,N-1){
		mfor(c,0,N-1){
			if(arr[r][c] - n > 0 && !ch[r][c]){
				ch[r][c] = true;
				res++;
				dfs(r,c,n);
			}
		}
	}
	return res;
}

int Solve(){
	int res = 1,ret;
	for(int i = Start; i <= End; ++i){
		ret = cal_live(i);
		res = ret > res ? ret : res;
	}
	return res;
}

int main(){
	Input();
	cout<<Solve()<<endl;
	return 0;
}