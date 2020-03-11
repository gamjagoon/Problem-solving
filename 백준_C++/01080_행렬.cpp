/*
Date : 03/078/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11097
summary : scc
*/
#include <iostream>
#include <array>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

array<string,50>A;
array<string,50>B;

void flib(int r,int c){
	mfor(i,r,r+3){
		mfor(j,c,c+3){
			A[i][j] = A[i][j] == '1' ? '0' : '1';
		}
	}
}

void solve(){
	io
	int R,C;
	cin>>R>>C;
	mfor(i,0,R){
		cin>>A[i];
	}
	mfor(i,0,R){
		cin>>B[i];
	}
	int cnt = 0;
	for(auto r = 0; r < R - 2; ++r){
		for(auto c = 0; c < C - 2; ++c){
			if(A[r][c] != B[r][c]){
				flib(r,c);
				cnt++;
			}
		}
	}
	bool flag = true;
	mfor(r,0,R){
		if (flag) {
			mfor(c,0,C) {
				if (A[r][c] != B[r][c]) {
					cout << "-1\n";
					flag = false;
					break;
				}
			}
		}
	}
	if(flag) cout << cnt << endl;
}

int main(){
	solve();
	return 0;
}