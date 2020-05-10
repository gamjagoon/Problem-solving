#include <iostream>
#include <vector>
#include <queue>
#define INF 40000
using namespace std;

int cost[251][251];

int N, M;
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N;++i){
		for(int j = 1; j <= N; ++j)
		{
			cost[i][j] = INF;
			if(i == j)
			{
				cost[i][j] = 0;
			}
		}
	}
	while(M--)
	{
		int u, v, b;
		cin >> u >> v >> b;
		if(b)
		{
			cost[u][v] = 0;
			cost[v][u] = 0;
        }
		else
		{
			cost[u][v] = 0;
			cost[v][u] = 1;
		}
	}
}

void Floyid()
{
	for(int k = 1; k <= N;++k)
	{
		for(int i = 1 ; i <= N;++i)
		{
			for(int j =1; j <= N;++j)
			{
				if(cost[i][j] > cost[i][k] + cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
}

void sovle()
{
	int t;cin>>t;
	while(t--)
	{
		int s,e;
		cin>>s>>e;
		cout<<cost[s][e]<<'\n';
	}
}


int main()
{
	input();
	Floyid();
	sovle();
}