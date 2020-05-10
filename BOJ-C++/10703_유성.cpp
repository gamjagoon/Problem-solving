/*
Date : 02/02/2020
version : gcc 6.3.0 c++14
problem : 구현
summary : 유성에서 땅까지 거리중 제일 가까운 거리만큼 이동시킨다
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

char map[3001][3001];

int R,C,u_e[3001],g_s[3001],min_val = 4000;
void mswap(char &a,char &b){
	char tmp = a;
	a = b;
	b = tmp;
}

void view_map(){
	mfor(r,1,R){
		mfor(c,0,C-1){
			cout<<map[r][c];
		}
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	string tmp;
	mfor(r,1,R){
		cin>>tmp;
		mfor(c,0,C-1){
			map[r][c] = tmp[c];
			if(map[r][c] == '.')continue;
			else if(map[r][c] == 'X'){
				u_e[c] = r;
			}
			else if(g_s[c] == 0 && u_e[c] != 0){
				g_s[c] = r - u_e[c] - 1;
				min_val = g_s[c] < min_val ? g_s[c] : min_val;
			}
		}
	}
	for(auto r = R; r >= 1; --r){
		mfor(c,0,C-1){
			if(map[r][c] == 'X'){
				mswap(map[r+min_val][c],map[r][c]);
			}
		}
	}
	view_map();
}