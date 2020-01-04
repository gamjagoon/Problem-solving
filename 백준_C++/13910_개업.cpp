#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector <int>v;
int dp[10001];
bool ch[20002] = {false};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	v.resize(m);
	for(int i = 0 ; i <= n; ++i)
	{
		dp[i] = 1000000000;
	}
	dp[0] = 0;
	ch[0] = 1;
	for(int i = 0 ; i < m; ++i){
		cin>>v[i];
	}
	for(auto i = 0; i < m; ++i)
	{
		ch[v[i]] = true;
		for(auto j = i+1 ; j < m; ++j){
			ch[v[i]+v[j]] = true;
		}
	}
	for(auto i = 1; i <= n; ++i)
	{
		if(!ch[i])continue;
		for(auto j = i; j <=n; ++j){
			if(dp[j] < dp[j-i]+1){
				dp[j] = dp[j];
			}
			else{
				dp[j] = dp[j-i]+1;
			}
		}
	}
	if(dp[n] ==1000000000)cout<<-1;
	else cout<<dp[n];
	return 0;
}