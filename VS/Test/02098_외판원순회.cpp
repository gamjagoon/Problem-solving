#include <iostream>
#define mfor(i,s,e) for(auto i = s; i<= e; ++i)
#define INF 20000000
using namespace std;

int N,dist[17][17],dp[17][1<<18],memo[17];
void init_memo(int n) {
	mfor(i, 1, n) {
		memo[i] = (1<<(i-1));
	}
	memo[0] = (1<<n) -1;
}

inline int mmin(const int& a, const int& b) {
	return a > b ? b : a;
}

int solve(int node, int visited) 
{
	if (visited == memo[0]) {
		if (dist[node][1] != 0) {
			return dist[node][1];
		}
	}
	int &ref = dp[node][visited];
	if(ref != 0)return ref;
	ref = INF;
	mfor(i, 1, N) {
		if (!(visited & memo[i]) && dist[node][i] != 0) {
			ref = mmin(ref , dist[node][i] + solve(i,visited | memo[i]));
		}
	}
	return ref;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i, 1, N) {
		mfor(j, 1, N) {
			cin>>dist[i][j];
		}
	}
	init_memo(N);
	cout<<solve(1,1);
	return 0;
}