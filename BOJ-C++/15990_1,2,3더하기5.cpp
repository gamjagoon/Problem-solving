#include <iostream>
#include <vector>
#include <algorithm>
#define M 1000000009
#define endl '\n'

using namespace std;

//Global
int dp[100001][4];
vector<int>tc;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	dp[1][1] = 1;dp[2][2] = 1;dp[3][3] = 1;
	dp[3][2] = 1;dp[3][1] = 1;
	int t;cin>>t;
	int m = 0;
	while(t--){
		int tmp;cin>>tmp;
		tc.push_back(tmp);
		m = tmp > m ? tmp : m;
	}
	for(int n = 3; n < m; n++){
		dp[n+1][1] += (dp[n][2] + dp[n][3]) % M;
		dp[n+1][2] += (dp[n-1][1] + dp[n-1][3]) % M;
		dp[n+1][3] += (dp[n-2][1] + dp[n-2][2]) % M;
	}
	for(auto i : tc){
		int res = dp[i][1];
		res %= M;
		res += dp[i][2];
		res %= M;
		res += dp[i][3];
		res %= M;
		cout<<res<<endl;
	}

}
