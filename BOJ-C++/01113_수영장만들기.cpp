#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

typedef pair<int,int> pii;
//Global

int R,C,H = 0,res = 0,L = 9;
array<array<int,50>,50>arr;
array<array<bool,50>,50>ch;
queue<pii>q;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

bool out_range(pii P){
	return P.first < 0|| P.second < 0 || P.first >= R || P.second >= C;
}

void bfs(){
	queue<pii>save;
	queue<pii>pool;
	bool not_pool=false;
	int sz = q.size();
	for(int i = 0; i < sz; ++i){
		pii now = q.front();
		q.pop();
		if(ch[now.first][now.second])continue;
		pool.push(now);
		ch[now.first][now.second]=true;
		not_pool = false;
		while(!pool.empty()){
			now = pool.front();
			pool.pop();
			save.push(now);
			for(int d = 0; d < 4; ++d){
				pii next{now.first+dir[d][0],now.second+dir[d][1]};
				if(out_range(next)){
					not_pool = true;
					continue;
				}
				if(arr[next.first][next.second] <= 0 || ch[next.first][next.second])continue;
				pool.push(next);
				ch[next.first][next.second] = true;
			}
		}
		if(not_pool){
			while(!save.empty()){
				now = save.front();
				save.pop();
				arr[now.first][now.second]--;
				if(arr[now.first][now.second] > 0){
					q.push(now);
				}
			}
		}else{
			while(!save.empty()){
				now = save.front();save.pop();
				res += arr[now.first][now.second];
			}
		}
	}
	for(int i = 0 ; i < R; ++i){
		for(int j = 0 ; j < C; ++j){
			ch[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>R>>C;
	string tmp;
	for(int i = 0 ; i < R;++i){
		cin>>tmp;
		for(int j = 0; j < C;++j){
			arr[i][j]=tmp[j]-'0';
			if(arr[i][j] > H)H = arr[i][j];
			if(arr[i][j] < L)L = arr[i][j];
		}
	}
	for(int i = 0 ; i < R;++i){
		for(int j = 0; j < C;++j){
			arr[i][j] = H - arr[i][j];
			if(arr[i][j] > 0){
				q.push({i,j});
			}
		}
	}
	for(int i = H-1; i > L || !q.empty();--i){
		bfs();
	}
	cout<<res;
}

