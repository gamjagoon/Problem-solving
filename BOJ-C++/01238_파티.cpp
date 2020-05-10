#include <iostream>
#include <array>

constexpr int INF = 1<<17;
using namespace std;

array<array<int,1001>, 1001>arr;

void solve(int N,int M,int X){
	// Initialize
	for(int k = 1 ; k <= N;++k){
		arr[k].fill(INF);
	}
	for(int a,b,c;M--;){
		cin>>a>>b>>c;
		arr[a][b] = c;
	}
	for(int i=1; i<=N; i++) arr[i][i] = 0; 
	for(int k = 1; k <= N;++k){
		for(int i = 1; i <= N;++i){
			for(int j = 1; j <= N; ++j){
				if(arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= N; ++i){
		int tmp = arr[i][X] + arr[X][i];
		res = tmp > res ? tmp : res;
	}
	cout<<res<<endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N,M,X;
	cin>>N>>M>>X;
	solve(N,M,X);
}
