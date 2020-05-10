#include<iostream>
#include<queue>
using namespace std;

typedef struct state{
	int val,clip,t;
}state;

int S;
bool ch[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>S;
	queue<state>q;
	q.push(state{1,0,0});
	ch[1][0] = true;
	state tmp;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp.val == S){
			cout<<tmp.t<<endl;
			return 0;
		}
		if(tmp.val > 1 && !ch[tmp.val-1][tmp.clip]){
			q.push(state{tmp.val-1,tmp.clip,tmp.t+1});
			ch[tmp.val-1][tmp.clip] = true;
		}
		if(tmp.clip != 0 && tmp.val+tmp.clip <= 1000 && !ch[tmp.val+tmp.clip][tmp.clip]){
			q.push(state{tmp.val+tmp.clip,tmp.clip,tmp.t+1});
			ch[tmp.val+tmp.clip][tmp.clip] = true;
		}
		if(!ch[tmp.val][tmp.val]){
			q.push(state{tmp.val,tmp.val,tmp.t+1});
			ch[tmp.val][tmp.val] = true;
		}
	}
}