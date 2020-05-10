/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/16928
summary : 그리디하게 가능할거 같은데
		 100가지만 보면되니까 bfs로 가자
*/
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int ch[101];
queue<int>q;
vector<int>pipe[101];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int T = n + m;
	while(T--){
		cin>>n>>m;
		pipe[n].push_back(m);
	}
	q.push(1);
	ch[1] = true;
	int t = 0,sz,now,next_val;
	bool flag = false;
	while(!q.empty()){
		sz = q.size();
		t++;
		for(auto i = 0 ; i < sz; ++i){
			now = q.front();
			if(now == 100){
				t--;
				flag = true;
			}
			q.pop();
			for(int d = 1; d <= 6; ++d){
				next_val = now + d;
				if(next_val > 100)break;
				if(!ch[next_val]){
					ch[next_val] = true;
					if(pipe[next_val].empty()){
						q.push(next_val);
					}
					else{
						next_val = pipe[next_val][0];
						if(!ch[next_val]){
							ch[next_val]=true;
							q.push(next_val);
						}
					}
				}
			}
		}
		if(flag)break;
	}
	cout<<t;
}