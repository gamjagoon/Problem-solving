#include <iostream>
#define INF 1000
using namespace std;
int n,m,A,B;
int map[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>A>>B;
	cin>>m;
	for(int i = 1; i <= n ;++i){
		for(int j = 1; j <= n ; ++j){
			map[i][j] = INF;
		}
	}
	int a,b;
	for(int i = 0 ; i < m ; ++i){
		cin>>a>>b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n ; ++i){
			for(int j = 1; j <= n ; ++j){
				if(map[i][j] > map[i][k] + map[k][j]){
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	if(map[A][B] != INF)cout<<map[A][B];
	else cout<<-1;
	return 0;
}