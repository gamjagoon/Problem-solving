#include <iostream>
using namespace std;

int dp[100001];
int val[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i = 1; i <= n;++i){
		cin>>val[i];
	}
	dp[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = val[i]; j <= k; ++j){
			dp[j] = dp[j] + dp[j - val[i]];
		}
	}
	cout<<dp[k];
	return 0;
}