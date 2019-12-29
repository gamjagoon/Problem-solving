#include <iostream>
#include <queue>
using namespace std;

int S,K;
bool ch[100001] ={false};
typedef pair<int,int> p;
queue<p>  q;

void move_1(int pos,int now_time)
{
	int res = pos+1;
	if(res < 100000 && !ch[res])
	{
		q.push(make_pair(res,now_time+1));
		ch[res] = true;
	}
}

void move_2(int pos,int now_time)
{
	int res = pos-1;
	if(res >=  0 && !ch[res])
	{
		q.push(make_pair(res,now_time+1));
		ch[res] = true;
	}
}

void move_3(int pos,int now_time)
{
	int res = pos*2;
	if(res <=  100000 && !ch[res])
	{
		q.push(make_pair(res,now_time+1));
		ch[res] = true;
	}
}

void bfs()
{
	q.push(make_pair(S,0));
	while(!q.empty()){
		int now = q.front().first;
		int t = q.front().second;
		if(now == K){
			cout<<t;
			return;
		}
		q.pop();
		move_1(now,t);
		move_2(now,t);
		move_3(now,t);
	}
	return ;
}


int main()
{
	cin>>S>>K;
	bfs();
	return 0;
}