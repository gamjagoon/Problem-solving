#include <iostream>
#define INF 1000000009
#define endl '\n'

using namespace std;
typedef long long ll;

//Global
bool arr[33][33];
ll dp[3][33][33];
int N;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	for(size_t r = 0 ; r < N; ++r){
		for(size_t c = 0 ; c < N; ++c){
			cin>>arr[r][c];
		}
	}
	dp[0][0][1] = 1;
	for(size_t r = 0 ; r < N; ++r){
		for(size_t c = 0 ; c < N; ++c){
			if(!arr[r][c+1])dp[0][r][c+1] += dp[0][r][c] + dp[1][r][c];
			if(!arr[r+1][c])dp[2][r+1][c] += dp[2][r][c] + dp[1][r][c];
			if(!arr[r+1][c+1] && !arr[r][c+1] && !arr[r+1][c]){
				dp[1][r+1][c+1] += dp[0][r][c] + dp[1][r][c] + dp[2][r][c];	
			}
		}
	}
	cout<<dp[0][N-1][N-1]+dp[1][N-1][N-1]+dp[2][N-1][N-1]<<endl;
}
