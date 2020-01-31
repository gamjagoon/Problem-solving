/*
Date : 01/30/2020
version : gcc 8.0.1 c++14
problem : 점프게임
summary : 완전탐색으로 풀었다
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

int n,k,res = 0;
int map[2][100000];
bool visit[2][100000];

typedef struct point{
	int line,num,time;
}p;


void bfs()
{
	bool end_game = false;
	queue<p>q;
	q.push({0,0,0});
	visit[0][0] = true;
	int len,idx,sec;
	while(!q.empty())
	{
		len = q.front().line;
		idx = q.front().num;
		sec = q.front().time;
		q.pop();
		if(idx + 1 == n){
			end_game = true;
		}
		else if(map[len][idx+1] == 1&& !visit[len][idx+1]){
			visit[len][idx+1] = true;
			q.push({len,idx+1,sec+1});
		}
		if(idx > 0 && map[len][idx-1] == 1 && !visit[len][idx-1] && idx -1 > sec){
			visit[len][idx-1] = true;
			q.push({len,idx-1,sec+1});
		}
		len =  ( len + 1 ) % 2;
		idx += k;
		if(idx >= n){
			end_game = true;
		}
		else if( map[len][idx] == 1&& !visit[len][idx]){
			visit[len][idx] = true;
			q.push({len,idx,sec+1});
		}
	}
	if(end_game)cout<<1<<endl;
	else cout<<0<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	mfor(i,0,1)
	{
		string Inp; cin >> Inp;
		for (int j = 0; j < Inp.length(); j++)
		{
			map[i][j] = Inp[j] - '0';
		}
	}
	//시작은 항상 0번 1인덱스부터;
	bfs();
	return 0;
}