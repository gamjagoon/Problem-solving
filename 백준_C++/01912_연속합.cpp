#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
typedef long long ll;
int n;
ll arr[100001],dp[100001];
int main()
{
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int res = -1000;
	mfor(i,1,n){
		cin>>arr[i];
	}
	dp[1] = arr[1];
	for(int i = 2; i <= n; ++i){
		if(dp[i-1] + arr[i] > arr[i] ){
			dp[i] = dp[i-1] + arr[i];
		}
		else{
			dp[i] = arr[i];
		}
		if(dp[i] > res)res = dp[i];
	}
	if(dp[1] > res)res = dp[1];
	cout<<res;
	return 0;
}