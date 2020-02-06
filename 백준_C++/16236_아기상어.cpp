/*
Date : 02/05/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/16236
summary : 시뮬레이션
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
struct point{
	int _r,_c;
};

int arr[20][20];
bool ch[20][20];
int dir[4][2] = {-1,0,0,-1,0,1,1,0};
int N;
point shark;
int shark_sz = 2;
int cnt = 0;
int gogi_cnt[7];
int result = 0;

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	mfor(r,0,N-1){
		mfor(c,0,N-1){
			cin>>arr[r][c];
			if(arr[r][c] == 0)continue;
			else if(arr[r][c] == 9){
				shark._r = r;
				shark._c = c;
			}
			else{
				gogi_cnt[arr[r][c]]++;
			}
		}
	}
}

void sizeup(){
	if(cnt == shark_sz){
		cnt = 0;
		shark_sz++;
	}
}

//전체고기중에 고기가 먹을수 있응게 있는가
bool if_eat(){
	for(int i = 1; i<shark_sz; ++i){
		if(gogi_cnt[i] != 0){
			return true;
		}
	}return false;
}
bool operator<(point a, point b) {
	if(a._r == b._r)return a._c > b._c;
	else return a._r > b._r;
}

bool Out_range(point &a){
	if(a._r < 0 || a._c < 0 || a._r >= N || a._c >= N)return true;
	return false;
}

bool bfs(){
	queue <point>q;
	priority_queue<point>cal;
	q.push(shark);
	int t = 1,sz;
	point npos,pre_pos;
	int res = -1;
	mfor(r,0,N-1)mfor(c,0,N-1)ch[r][c] = false;
	ch[shark._r][shark._c] = true;
	while(!q.empty()){
		sz = q.size();
		for(int i = 0 ; i < sz; ++i)
		{
			pre_pos = q.front();
			q.pop();
			mfor(d,0,3){
				npos._r = pre_pos._r + dir[d][0];
				npos._c = pre_pos._c + dir[d][1];
				if(!Out_range(npos) && !ch[npos._r][npos._c]){
					if(arr[npos._r][npos._c] > shark_sz)continue;
					else if(arr[npos._r][npos._c] == shark_sz ||arr[npos._r][npos._c] == 0){
						ch[npos._r][npos._c] = true;
						q.push(npos);
					}
					else {
						ch[npos._r][npos._c] = true;
						cal.push(npos);
					}
				}
			}
		}
		if(!cal.empty()){
			npos = cal.top();
			gogi_cnt[arr[npos._r][npos._c]]--;
			cnt++;
			arr[shark._r][shark._c] = 0;
			shark = npos;
			arr[npos._r][npos._c] = 9;
			sizeup();
			res = t;
			while(!cal.empty())cal.pop();
			break;
		}
		t++;
	}
	while(!q.empty())q.pop();
	if(res != -1){
		result += res;
		return true;
	}
	else {
		return false;
	}
}

int main(){
	Input();
	while(bfs()){
		if(!if_eat()){
			break;
		}
	}
	cout<<result;
	return 0;
}