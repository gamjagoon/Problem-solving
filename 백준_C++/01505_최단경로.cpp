#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int N,E;
int cost[801][801];
int dist[801];
int A,B;

void view_cost()
{
	for(int i =1; i <= N; ++i){
		for(int j = 1; j <= N;++j){
			if(cost[i][j]== INF){
				cout<<"INF ";
			}
			else{
				cout<<cost[i][j]<<' ';
			}
		}
		cout<<'\n';
	}
	cout<<'\n';
}
void init()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>E;
	int a,b,c;
	for(int i = 1; i <= N;++i){
		for(int j = 1; j <= N;++j){
			cost[i][j] = INF;
		}
	}
	for(int i = 0; i < E;++i)
	{
		cin>>a>>b>>c;
		if(c < cost[a][b]){
			cost[a][b] = c;cost[b][a] = c;
		}
	}
	cin>>A>>B;
}

void 

int main()
{
	init();
	return 0;
}