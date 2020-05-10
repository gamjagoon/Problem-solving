#include <iostream>
#include <cstring>

#define nfor(i,a,b) for(auto i = a;i < b;i++)
using namespace std;

int dp[503][503];
int n;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	auto mmax = [](int a,int b)->int{if(a >= b)return a;return b;};
	cin>>n;
	cin>>dp[1][1];
	if(n == 1)
	{
		cout<<dp[1][1];	
		return 0;
	}
	nfor(i,2,n+1){
		cin>>dp[i][1];
		dp[i][1] += dp[i-1][1];
		nfor(j,2,i){
			cin>>dp[i][j];
			dp[i][j] += mmax(dp[i-1][j],dp[i-1][j-1]);
		}
		cin>>dp[i][i];
		dp[i][i]+=dp[i-1][i-1];
	}
	int ret = -1;
	for(int i = 1; i <= n;i++){
		ret = mmax(ret,dp[n][i]);
	}
	cout<<ret;
}
