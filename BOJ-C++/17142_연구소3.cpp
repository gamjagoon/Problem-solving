/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/17142
summary : 구현 시뮬
*/
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

int ori_map[50][50],cal_map[50][50];
bool ch[50][50];
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int ori_blank = 0,result = 4000,N,M,b_len;
struct point{
	int _r,_c;
};
vector <point>b;
vector <int>v;

void view_map(int arr[][50]){
	mfor(r,0,N-1){
		mfor(c,0,N-1){
			cout<<arr[r][c];
		}cout<<endl;
	}
	cout<<endl;
}
void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	mfor(r,0,N-1){
		mfor(c,0,N-1){
			cin>>ori_map[r][c];
			if(ori_map[r][c] == 2){
				ori_map[r][c] = -1;
				b.push_back({r,c});
			}
			else if(ori_map[r][c] == 0){
				ori_blank++;
			}
			else if(ori_map[r][c] == 1){
				ori_map[r][c] = 2501;
			}
		}
	}
	b_len = b.size();
}

bool Out_range(int r,int c){
	if(r < 0 || c < 0 || r >= N || c >= N)return true;
	return false;
}

void Solve(int n,int pre){
	if(n == M){
		mfor(r,0,N-1){
			mfor(c,0,N-1){
				cal_map[r][c] = ori_map[r][c];
				ch[r][c] = false;
			}
		}
		int b_num;
		int res = ori_blank;
		queue<point>q;
		for(auto i : v){
			b_num = i;
			q.push({b[b_num]._r,b[b_num]._c});
		}
		int r,c,nr,nc,t = 1,sz;
		while(!q.empty()){
			sz = q.size();
			for(auto i = 0 ; i < sz; ++i){
				r = q.front()._r;
				c = q.front()._c;
				q.pop();
				mfor(d,0,3){
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					if(!Out_range(nr,nc) && !ch[nr][nc] && cal_map[nr][nc] <= 0){
						ch[nr][nc] = true;
						if(cal_map[nr][nc] == 0){
							cal_map[nr][nc] = t;
							res--;
						}
						q.push({nr,nc});
					}
				}
			}
			if(res == 0)break;
			else t++;
		}
		while(!q.empty())q.pop();
		if(res == 0){
			result = result > t ? t : result;
		}
		return;
	}
	for(int i = pre+1; i < b_len; ++i){
		v.push_back(i);
		Solve(n+1,i);
		v.pop_back();
	}
}

int main(){
	Input();
	//빈칸의 갯수가 0 이면 0출력 종료
	if(ori_blank == 0){
		cout<<ori_blank;
		return 0;
	}
	//검사 실행
	Solve(0,-1);
	if(result == 4000)cout<<-1;
	else cout<<result;
	return 0;
}