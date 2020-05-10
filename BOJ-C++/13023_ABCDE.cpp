#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int n,m;
bitset<2000> ch;
vector<int>node[2000];

void dfs(int now,int level){
	if(level == 4){
		cout<<1;
		exit(0);
	}
	else {
		for(int i = 0; i < node[now].size(); ++i){
			if(!ch.test(node[now][i])){
				ch.set(node[now][i]);
				dfs(node[now][i],level+1);
				ch.reset(node[now][i]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a,b;
	for(int i = 0 ; i < m; ++i){
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	if(m < 4)cout<<0;
	else{
		//모든 노드 시작지점에서 출발
		for(int i = 0 ; i < n; ++i){
			ch.set(i);
			dfs(i,0);
			ch.reset(i);
		}
	}
	return 0;
}