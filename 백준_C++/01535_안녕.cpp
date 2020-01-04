#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int N;
typedef pair<int,int>p;
vector<p>v;
int dp[21][101];


int calc()
{
	int res = 0;
	dp[1][100-v[1].first] = v[1].second;
	mfor(i,2,N){
		dp[i][100-v[i].first] = v[i].second;
		for(int j = 100 ; j >0 ; --j)
		{
			if(j + v[i].first <= 100 && dp[i-1][j+v[i].first] != 0){
				dp[i][j] = max(dp[i-1][j+v[i].first] + v[i].second,dp[i-1][j]);
			}
			else{
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			}
		
		}
	}
	mfor(i,1,100){
		res = max(dp[N][i],res);
	}
	return res;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	v.resize(N+1);
	mfor(i,1,N){
		cin>>v[i].first;
	}
	mfor(i,1,N){
		cin>>v[i].second;
	}
	memset(dp,0,sizeof(dp));
	cout<<calc();
	return 0;
}