#include <iostream>
#include <cstring>
using namespace std;

int dp[5000] ={ };
int val[2] = {3, 5};

int main()
{
	int n;
	cin>>n;
	for(int i = 0 ; i <= n; ++i){
		dp[i] = 2000;
	}
	dp[0] = 0;
	for(int i = 0 ; i <= 1; ++i){
		for(int j = val[i] ; j <= n;++j){
			if(dp[j] >= dp[j - val[i]] + 1){
				dp[j] = dp[j - val[i]] + 1;
			}
		}
	}
	if(dp[n] == 2000)cout<<-1;
	else cout<<dp[n];
}