/*
Date : 02/06/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/12100
summary : 구현
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

//보드의크기
int N,arr[20][20],ans= 0;

void cpy(int a[20][20],const int b[20][20]){
	mfor(i,0,N-1){
		mfor(j,0,N-1){
			a[i][j] = b[i][j];
		}
	}
}

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i,0,N-1){
		mfor(j,0,N-1){
			cin>>arr[i][j];
		}
	}
}

void bordmax(int X[20][20]){
	mfor(i,0,N-1){
		mfor(j,0,N-1){
			ans = X[i][j] > ans ? X[i][j] : ans;
		}
	}
}

void roate90(int X[20][20]){
	int tmp[20][20] = {0,};
	mfor(i,0,N-1){
		mfor(j,0,N-1){
			tmp[j][N-i-1] = X[i][j];
		}
	}
	cpy(X,tmp);
}

void convert(int X[20][20]){
	int tmp[20][20] = {0,};
	bool can;
	mfor(i,0,N-1){
		int ch = -1,can = false;
		mfor(j,0,N-1){
			if(X[i][j] == 0)continue;
			if(can && X[i][j] == tmp[i][ch]){
				tmp[i][ch]*=2;
				can = false;
			}
			else {
				tmp[i][++ch] = X[i][j];
				can = true;
			}
		}
	}
	cpy(X,tmp);
}

void dfs(int X[20][20],int cnt){
	if(cnt == 5){
		bordmax(X);
		return;
	}
	mfor(i,0,3){
		auto bord = new int[20][20];
		cpy(bord,X);
		convert(bord);
		dfs(bord, cnt+1);
		roate90(X);
	}
}

int main(){
	Input();
	dfs(arr,0);
	cout<<ans;
	return 0;
}