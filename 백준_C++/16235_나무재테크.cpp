/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/16235
summary : 
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
struct point{
	int _r,_c;
};
int N,M,K;
int A[11][11],arr[11][11],Y[11][11];
deque<int> trees[11][11];
queue<point>dolist;
int Live = 0;

int dir[8][2] = {
	1,0, 1,1 ,1,-1 ,0,1 ,0,-1 ,-1,0 ,-1,1, -1,-1
};

bool Out_range(int r,int c){
	if(r <= 0 || c <= 0 || r > N || c > N)return true;
	return false;
}

//나무 양분과 양분 보급량설정
//나무를 심어 뒀다
void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	mfor(i,1,N){
		mfor(j,1,N){
			cin>>A[i][j];
			arr[i][j] = 5;
		}
	}
	int r,c,ag;
	mfor(i,1,M){
		cin>>r>>c>>ag;
		dolist.push({r,c});
		trees[r][c].push_back(ag);
	}
	Live+=M;
}
bool com(int a, int b){
	return a < b;
}

void spring(){
	int r,c,nr,nc,sz,res = 0;
	sz = dolist.size();
	for(int i = 0 ; i < sz; ++i){
		r = dolist.front()._r;
		c = dolist.front()._c;
		dolist.pop();
		int now_tree,len = trees[r][c].size();
		for(int j = 0 ; j < len; j++){
			now_tree = trees[r][c].front();trees[r][c].pop_front();
			if(arr[r][c] >= now_tree){
				trees[r][c].push_back(now_tree+1);
				res++;
				arr[r][c] -= now_tree;
			}
			else{
				Y[r][c]+=(now_tree/2);
			}
		}
		if(!trees[r][c].empty()){
			dolist.push({r,c});
		}
	}
	Live = res;
}

void summer(){
	mfor(r,1,N){
		mfor(c,1,N){
			arr[r][c] += Y[r][c];
			Y[r][c] = 0;
		}
	}
}

void far(){
	int r,c,nr,nc,res = 0;
	while(!dolist.empty()){
		r = dolist.front()._r;
		c = dolist.front()._c;
		dolist.pop();
		int len = trees[r][c].size();
		for(int j = 0 ; j < len; j++){
			if(trees[r][c][j] % 5 == 0){
				mfor(d,0,7){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					if(!Out_range(nr,nc)){
						trees[nr][nc].push_front(1);
					}
				}
			}
		}
	}
	mfor(i,1,N){
		mfor(j,1,N){
			if(!trees[i][j].empty()){
				dolist.push({i,j});
			}
		}
	}
}


int main(){
	Input();
	for(int t = 1; t <= K; ++t){
		spring();
		if(Live == 0){
			break;
		}
		summer();
		far();
		mfor(r,1,N){
			mfor(c,1,N){
				arr[r][c] += A[r][c];
			}
		}
	}
	Live = 0;
	mfor(i,1,N)mfor(j,1,N)Live += trees[i][j].size();
	cout<<Live;
	return 0;
}