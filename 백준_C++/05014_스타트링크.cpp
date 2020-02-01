/*
Date : 02/01/2020
version : gcc 6.3.0 c++14
problem : 스타트링크
summary : bfs 문제
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)

using namespace std;

//F 최대층 S 시작층 G 목표 
int F,S,G,U,D;
bool visit[1000001];

int main(){
	cin>>F>>S>>G>>U>>D;
	//건물의 최하층은 1층
	visit[S] = true;
	queue<int>q;
	q.push(S);
	int sz,res = -1,t = 0;
	bool flag = false;
	int now_pos,next_pos;
	while(!q.empty()){
		sz = q.size();
		mfor(i,0,sz-1){
			now_pos = q.front();
			if(now_pos == G){
				flag = true;
				res = t;
				break;
			}
			q.pop();
			if(now_pos - D >= 1 && !visit[now_pos - D]){
				visit[now_pos - D] = true;
				q.push(now_pos - D);
			}
			if(now_pos + U <= 1000000 && !visit[now_pos + U]){
				visit[now_pos + U] = true;
				q.push(now_pos + U);
			}
		}
		if(flag)break;
		t++;
	}
	if(res == -1)cout<<"use the stairs";
	else cout<<res;
	return 0;
}