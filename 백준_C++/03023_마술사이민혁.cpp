/*
Date : 02/16/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/3023
summary : 구현
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int r,c;
int R,C;
int a,b;
char arr[101][101];

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>r>>c;
	string tmp;
	mfor(i,1,r){
		cin>>tmp;
		mfor(j,1,c){
			arr[i][j] = tmp[j-1];
		}
	}
}

void Solve(){
	R = 2*r;
	C = 2*c;
	for(int i = 1;i <= r; ++i){
		for(int j = c+1; j<=C; ++j){
			arr[i][j] = arr[i][C-j+1];
		}
	}
	for(int i = r+1;i <= R; ++i){
		for(int j = 1; j<=c; ++j){
			arr[i][j] = arr[R-i+1][j];
		}
		for(int j = c+1; j<=C; ++j){
			arr[i][j] = arr[R-i+1][C-j+1];
		}
	}
}

int main(){
	Input();
	Solve();
	cin>>a>>b;
	arr[a][b] = arr[a][b] == '#' ? '.' :'#';
	mfor(i,1,R){
		mfor(j,1,C){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}