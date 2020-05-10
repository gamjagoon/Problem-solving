/*
Date : 02/04/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/17822
summary : 원판 돌리기
*/
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int N,M,T;
//배열의 시작은 12 시다
int arr[51][50];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

void rotate(int num,int d,int k){
	if(k == 0)return;
	int s,len = M-1,e;
	if(d == 0){
		s = M - k;
		e = s - 1;
	}
	else {
		s = k;
		e = s - 1;
	}
	queue<int>q;
	for(int i = s; i < M; ++i){
		q.push(arr[num][i]);
	}
	for(int i = 0; i <= e; ++i){
		q.push(arr[num][i]);
	}
	s = q.size();
	for(int i = 0 ; i < s; ++i){
		arr[num][i] = q.front();
		q.pop();
	}
}

int dfs(int r, int c, int num){
	int nr,nc;
	int res = 0;
	int cnt = 0;
	for(int i = 0; i <= 3; ++i){
		nr = r + dir[i][0];
		nc = c + dir[i][1];
		if(nr <= N && nr >= 1 )
		{
			if(nc >= 0 && nc < M && arr[nr][nc] == num){
				arr[nr][nc] = 0;
				cnt++;
				res += dfs(nr,nc,num);
			}
			else if(nc == -1 && arr[nr][M-1] == num){
				arr[nr][M-1] = 0;
				cnt++;
				res += dfs(nr,M-1,num);
			}
			else if(nc == M && arr[nr][0] == num){
				arr[nr][0] = 0;
				cnt++;
				res += dfs(nr,0,num);
			}
		}
	}
	return cnt;
}

void mid_cal(){
	//인접한수를 지운다
	int cnt = 0;
	mfor(i,1,N){
		mfor(j,0,M-1){
			if(arr[i][j] == 0)continue;
			cnt += dfs(i,j,arr[i][j]);
		}
	}
	if(cnt == 0){
		cnt = 0;
		int Sum = 0;
		mfor(i,1,N){
			mfor(j,0,M-1){
				if(arr[i][j] != 0){
					Sum+=arr[i][j];
					cnt++;
				}
			}
		}
		if(Sum == 0)return;
		int l = Sum / cnt;
		int m = Sum % cnt;
		mfor(i,1,N){
			mfor(j,0,M-1){
				if(arr[i][j] == 0)continue;
				if(arr[i][j] == l && m == 0){
					continue;
				}
				else if(arr[i][j] > l){
					arr[i][j] -= 1;
				}
				else{
					arr[i][j] += 1;
				}
			}
		}
	}
	return;
}

int cal(){
	int ret = 0;
	mfor(i,1,N){
		mfor(j,0,M-1){
			ret += arr[i][j];
		}
	}
	return ret;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>T;
	mfor(i,1,N){
		mfor(j,0,M-1){
			cin>>arr[i][j];
		}
	}
	int x,d,k;
	k %= M;
	mfor(i,0,T-1){
		cin>>x>>d>>k;
		for(int j = x; j <= N; j += x){
			rotate(j,d,k);
		}
		mid_cal();
	}
	cout<<cal();
	return 0;
}