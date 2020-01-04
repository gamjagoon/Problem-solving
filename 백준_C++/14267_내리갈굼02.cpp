#include <iostream>
#include <vector>
using namespace std;

vector<int>g[100010];
int s[100010];

void dfs(int now)
{
	for(auto i : g[now]){
		s[i] += s[now];
		dfs(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
	{
		int t; cin>>t;
		if(i != 1)g[t].push_back(i);
	}

	while(m--){
		int a,b; cin>>a>>b;
		s[a]+=b;
	}
	dfs(1);
	for(int i = 1; i <= n ; ++i)cout<<s[i]<<' ';
}