#include <iostream>
using namespace std;

int dp[10001];
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
	for(int i = 0 ; i<= k;++i){
		dp[k] = 101;
	}
	dp[0] = 0;
	for(int i = 1; i <= n;++i)
	{
		for(int j = val[i] ; j <= k; ++j){
			if( dp[j] > dp[j - val[i]] +1){
				dp[j] = dp[j - val[i]] + 1;
			}
		}
	}
	cout<<dp[k];
	return 0;
}