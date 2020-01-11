#include <iostream>
#include <queue>
#define mfor(i,s,e) for(auto i = s; i <= e;++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>p;

int n;
int arr[100][100],dir[2][2] = {{1,0},{0,1}};
ll dp[100][100];
ll dfs(int r,int c)
{
	if(r == n-1 && c == n-1)return 1;
	if(r >= n || c >= n || arr[r][c] == 0)return 0;
	if(dp[r][c] != 0)return dp[r][c];
	int res = arr[r][c];
	return dp[r][c] = dfs(r+res,c) + dfs(r,c+res);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	mfor(r, 0, n - 1) {
		mfor(c, 0, n - 1) {
			cin>>arr[r][c];
			dp[r][c] = 0;
		}
	}
	cout<<dfs(0,0);
}