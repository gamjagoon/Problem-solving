/*
Date : 02/21/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/14503
summary : 구현
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

//방향벡터 이동하는쪽
//0 북 1 동 2 남 3 서
int dir[4][2] ={
	{-1,0},{0,1},{1,0},{0,-1}
};
//멥구조
int R,C,arr[50][50];

//로봇청소기
int rr,rc,rd;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>R>>C;
	cin>>rr>>rc>>rd;
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			cin>>arr[r][c];
		}
	}
}

int rotate(int d){
	if(d <= 0)d = 3;
	else d--;
	return d;
}

bool find_blank(){
	int nd = rotate(rd);
	int nr = rr+dir[nd][0],nc = rc+dir[nd][1];
	rd = nd;
	if(arr[nr][nc] == 0){
		rr = nr;
		rc = nc;
		return true;
	}
	return false;
}

bool back_is_blank(){
	int bd = rotate(rotate(rd));
	int br = rr + dir[bd][0],bc = rc + dir[bd][1];
	if(arr[br][bc] != 1){
		rr = br;
		rc = bc;
		return true;
	}
	return false;
}

int main(){
	Input();
	bool flag;
	int t;
	int res = 0;
	while(1){
		if(arr[rr][rc] == 0){
			res++;
			arr[rr][rc] = 2;
		}
		flag = true;t = 4;
		while(t--){
			if(find_blank()){
				flag = true;
				break;
			}
			else flag = false;
		}
		if(!flag && !back_is_blank()){
			break;
		}
	}
	cout<<res;
}