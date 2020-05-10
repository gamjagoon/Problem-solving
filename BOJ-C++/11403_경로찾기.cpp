#include <iostream>
#define INF 200
using namespace std;
int n,map[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 0; i < n;++i){
		for(int j = 0 ; j < n; ++j){
			cin>>map[i][j];
			if( map[i][j] == 0){
				map[i][j] = INF;
			}
		}
	}
	for(int k = 0 ; k < n ; ++k){
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(map[i][j] > map[i][k] + map[k][j]){
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for(int i = 0; i < n;++i){
		for(int j = 0 ; j < n; ++j){
			if(map[i][j]  < INF){
				cout<<"1 ";
			}
			else{
				cout<<"0 ";
			}
		}cout<<'\n';
	}

}