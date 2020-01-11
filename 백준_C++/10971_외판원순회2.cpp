#include <iostream>
#define INF 1000000000
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int result = INF,N;
int map[10][10];
bool ch[10]= {false};

void dfs(int n,int v,int pre)
{
	if(n == N){
		if(map[pre][0] > 0 && result > v + map[pre][0]){
			result = v + map[pre][0];
		}
		return;
	}
	else{
		for(int i = 0 ; i < N;++i){
			if(!ch[i] && map[pre][i] > 0 && v + map[pre][i] < result){
				ch[i] = true;
				dfs(n+1,v+map[pre][i],i);
				ch[i] = false;
			}
		}
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i,0,N-1){
		ch[i] = false;
		mfor(j,0,N-1){
			cin>>map[i][j];
		}
	}
	ch[0] = true;
	dfs(1,0,0);
	cout<<result;
	return 0;
}