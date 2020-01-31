/*
Date : 01/30/2020
version : gcc 6.3.0 c++14
problem : 데스나이트
summary : 최소이동횟수를 구해야하므로 bfs문제다
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)

using namespace std;
typedef long long ll;
typedef struct point{
	int r,c;
}p;

bool map[200][200];
int dir[6][2] = {-2,-1,-2,1,0,-2,0,2,2,-1,2,1};

int n,r1,c1,r2,c2;

bool inrange(p tmp){
	return tmp.r >= 0 && tmp.c >= 0 && tmp.r < n && tmp.c < n;
}

int main(){
	cin>>n>>r1>>c1>>r2>>c2;
	queue<p>q;
	q.push({r1,c1});
	map[r1][c1] = true;
	int sz,res = 50000,t = 0;
	bool flag = false;
	p now,next;
	while(!q.empty()){
		sz = q.size();
		mfor(i,0,sz-1){
			now = q.front();
			if(now.r == r2 && now.c == c2){
				res = t;
				flag = true;
				break;
			}
			q.pop();
			mfor(j,0,5){
				next.r = now.r + dir[j][0];
				next.c = now.c + dir[j][1];
				if(inrange(next) && map[next.r][next.c] == 0){
					map[next.r][next.c] = 1;
					q.push(next);
				}
			}
		}
		if(flag)break;
		t++;
	}
	if(res == 50000)cout<<-1;
	else cout<<res;
	return 0;
}