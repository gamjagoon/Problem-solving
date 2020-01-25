#include <iostream>
#include <cstring>
using namespace std;

int dp[11];

int main()
{
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for(int i = 3; i<= n; ++i){
			if(dp[i] != 0)continue;
			dp[i] = dp[i-2] + dp[i-1]+dp[i-3];
		}
		cout<<dp[n]<<'\n';
	}
}