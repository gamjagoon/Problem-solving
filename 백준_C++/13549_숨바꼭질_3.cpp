#include <iostream>
#include <queue>
using namespace std;

int K, X;
bool ch[100001][3];
typedef struct time {
	int pos,t;
}t;

void bfs(int X){
	queue<t>q;
	q.push(t{X,0});
	t tmp,copy_tmp;
	while(!q.empty()){
		tmp = q.front();
		if(tmp.pos == K){
			cout<<tmp.t;
			return;
		}
		q.pop();
		copy_tmp.pos = tmp.pos;
		int thr = K/2;
		while(copy_tmp.pos != 0 && copy_tmp.pos <= 50000){
			copy_tmp.pos*= 2;
			if(!ch[copy_tmp.pos][2]){
				ch[copy_tmp.pos][2] = true;
				q.push(t{copy_tmp.pos,tmp.t});
			}
		}
		if(tmp.pos + 1 <= K &&!ch[tmp.pos + 1][1]){
			ch[tmp.pos + 1][1] = true;
			q.push(t{tmp.pos+1,tmp.t+1});
		}
		if(tmp.pos - 1 >= 0 && !ch[tmp.pos -1][0]){
			ch[tmp.pos - 1][0] = true;
			q.push(t{tmp.pos-1,tmp.t+1});
		}
	}
}

int main()
{
	cin>>X>>K;
	bfs(X);
	return 0;
}