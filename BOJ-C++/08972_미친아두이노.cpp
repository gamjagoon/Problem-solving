/*
Date : 02/01/2020
version : gcc 6.3.0 c++14
problem : 미친아두이노
summary : 구현문제
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef struct point{
	int r,c;
}p;

char map[100][100];
queue <p>dolist;
int R,C,ri,ci;
int dir[10][2] = {0,0, 1,-1, 1,0, 1,1, 0,-1, 0,0,
				  0,1, -1,-1, -1,0, -1,1};

inline int distance(int r,int c){
	if(r < 0 || c < 0)return 200;
	return abs(r-ri) + abs(c-ci);
}

void view_map(){
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			cout<<map[r][c];
		}
		cout<<endl;
	}
}


bool solve(char a,int t){
	//업데이트할 맵 만들기
	int upmap[100][100];
	memset(upmap,0,sizeof(upmap));
	//나의 아두이노 업데이트
	ri += dir[a-'0'][0];
	ci += dir[a-'0'][1];
	if(map[ri][ci] == 'R'){
		cout<<"kraj "<<t<<endl;
		return false;
	}
	else{
		upmap[ri][ci] = 'I';
	}
	//미친아두이노의 이동
	p now;
	while(!dolist.empty()){
		now = dolist.front();
		dolist.pop();
		int idx = 1;
		int val = distance(now.r+dir[1][0],now.c+dir[1][1]);
		int tmp;
		mfor(i,2,9){
			tmp = distance(now.r+dir[i][0],now.c+dir[i][1]);
			if(val > tmp){
				val =  tmp;
				idx = i;
			}
		}
		now.r += dir[idx][0];
		now.c += dir[idx][1];
		if(upmap[now.r][now.c] == 'I'){
			cout<<"kraj "<<t<<endl;
			return false;
		}
		else{
			upmap[now.r][now.c]+=1;
		}
	}
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			if(upmap[r][c] == 'I'){
				map[r][c] = 'I';
			}
			else if(upmap[r][c] == 1){
				map[r][c] = 'R';
				dolist.push({r,c});
			}
			else{
				map[r][c] = '.';
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	string tmp;
	mfor(r,0,R-1){
		cin>>tmp;
		mfor(c,0,C-1){
			map[r][c] = tmp[c];
			if(map[r][c] == '.')continue;
			else if(map[r][c] == 'I'){
				ri = r;
				ci = c;
			}
			else {
				dolist.push({r,c});
			}
		}
	}
	cin>>tmp;
	bool flag = true;
	mfor(a,0,tmp.length()-1){
		flag = solve(tmp[a],a+1);
		if(!flag){
			break;
		}
	}
	if(flag){
		view_map();
	}
	return 0;
}