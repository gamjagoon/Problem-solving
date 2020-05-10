/*
Date : 02/02/2020
version : gcc 6.3.0 c++14
problem : 구현
summary : 빡구현 문제이다
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

char arr[7][7];
int dir[8][2] = {
	{1,0},{1,1},{1,-1},{-1,0},
	{-1,1},{-1,-1},{0,1},{0,-1}
};

inline bool inrange(int r,int c){
	return r >= 1 && c >= 1 && r <= 6 && c <= 6;
}

queue<pair<int,int> >pii;

bool ch_next(int r,int c,int d ,char next_color){
	r += dir[d][0];
	c += dir[d][1];
	if(inrange(r,c) && arr[r][c] != '.'){
		if(arr[r][c] != next_color)return true;
		else{
			pii.push({r,c});
			return ch_next(r,c,d,next_color);
		}
	}
	else return false;
}

void gamedo(int r,int c,char ncolor){
	arr[r][c] = ncolor;
	char next_color = ncolor == 'B' ? 'W' : 'B';
	int nr,nc;
	mfor(d,0,7){
		nr = r + dir[d][0];
		nc = c + dir[d][1];
		bool flag = false;
		if(inrange(nr,nc) && arr[nr][nc] == next_color){
			pii.push({nr,nc});
			flag = ch_next(nr,nc,d,next_color);
		}
		while(flag && !pii.empty()){
			arr[pii.front().first][pii.front().second] = ncolor;
			pii.pop();
		}
		while(!pii.empty())pii.pop();
	}
}

void view_arr_cal(){
	int w = 0,b = 0;
	mfor(r,1,7){
		mfor(c,1,7){
			cout<<arr[r][c];
			if(arr[r][c] == 'W'){
				w++;
			}
			else if(arr[r][c] == 'B'){
				b++;
			}
		}
		cout<<endl;
	}
	if(w > b)cout<<"White";
	else cout<<"Black";
}

int main()
{
	int N;
	cin>>N;
	mfor(r,1,7)mfor(c,1,7)arr[r][c] = '.';
	arr[3][3] = 'W';
	arr[4][4] = 'W';
	arr[3][4] = 'B';
	arr[4][3] = 'B';
	int r,c;
	char col;
	mfor(i,1,N){
		cin>>r>>c;
		if(i % 2 == 1)col = 'B';
		else col = 'W';
		gamedo(r,c,col);
	}
	view_arr_cal();
	return 0;
}