/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/17144
summary : 구현문제
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

int ori_map[50][50];
int upmap[50][50];
int R,C,T,pos,result = 0;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};

bool Out_range(int r,int c){
	if(r < 0 || c < 0 || r >= R || c >= C)return true;
	else return false;
}
	// mfor(r,0,R-1){
	// 	mfor(c,0,C-1){
			
	// 	}
	// }

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>T;
	mfor(r,0,R-1){
		mfor(c,0,C-1){
			cin>>ori_map[r][c];
			if(ori_map[r][c] == -1){
				pos = r;
			}
			else {
				result += ori_map[r][c];
			}
		}
	}
}

void Grow(){
	mfor(r,0,R- 1){
		mfor(c,0,C-1){
			upmap[r][c] = 0;
		}
	}
	upmap[pos][0] = -1;
	upmap[pos-1][0] = -1;
	queue<pair<int,int> >q;
	mfor(r,0,R- 1){
		mfor(c,0,C-1){
			int n = 0;
			int nr,nc;
			if(ori_map[r][c] > 0){
				mfor(d,0,3){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					if(!Out_range(nr,nc) && ori_map[nr][nc] != -1){
						q.push({nr,nc});
					}
				}
				n = ori_map[r][c] / 5;
				while(!q.empty()){
					upmap[q.front().first][q.front().second] += n;
					ori_map[r][c] -= n;
					q.pop();
				}
				upmap[r][c] += ori_map[r][c];
			}
		}
	}
	int res = 0;
	mfor(r,0,R- 1){
		mfor(c,0,C-1){
			ori_map[r][c] = upmap[r][c];
			res += upmap[r][c];
		}
	}
	res +=2;
	result = res;
}

void Re(){

	int mr_1 = pos-1;
	int mr_2 = pos;
	int mc = 0;
	int tmp = ori_map[mr_1][C-1];
	for(int c = C-1; c > 1; c--){
		ori_map[mr_1][c] = ori_map[mr_1][c-1];
	}
	ori_map[mr_1][1] = 0;
	int tmp2 = ori_map[0][C-1];
	for(int r = 0; r < mr_1 - 1; ++r){
		ori_map[r][C-1] = ori_map[r+1][C-1];
	}
	ori_map[mr_1-1][C-1] = tmp;
	tmp = ori_map[0][0];
	for(int c = 0; c < C-2;++c){
		ori_map[0][c] = ori_map[0][c+1];
	}
	ori_map[0][C-2] = tmp2;
	for(int r = mr_1-1; r > 1; --r){
		ori_map[r][0] = ori_map[r-1][0];
	}
	ori_map[1][0] = tmp;
	

	tmp = ori_map[mr_2][C-1];
	for(int c = C-1; c > 1; c--){
		ori_map[mr_2][c] = ori_map[mr_2][c-1];
	}
	ori_map[mr_2][1] = 0;
	tmp2 = ori_map[R-1][C-1];
	for(int r = R-1; r > mr_2; --r){
		ori_map[r][C-1] = ori_map[r-1][C-1];
	}
	ori_map[mr_2+1][C-1] = tmp;
	tmp = ori_map[R-1][0];
	for(int c = 0; c < C-1;++c){
		ori_map[R-1][c] = ori_map[R-1][c+1];
	}
	ori_map[R-1][C-2] = tmp2;
	for(int r = mr_2+1; r < R-2; ++r){
		ori_map[r][0] = ori_map[r+1][0];
	}
	ori_map[R-2][0] = tmp;
	int res = 0;
	mfor(r,0,R- 1){
		mfor(c,0,C-1){
			res += ori_map[r][c];
		}
	}
	res +=2;
	result = res;
}


int main(){
	Input();
	while(T--){
		Grow();
		Re();
		if(result == 0)break;
	}
	cout<<result;
	return 0;
}