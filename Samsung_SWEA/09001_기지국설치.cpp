#include <iostream>
#define INF 1000000
using namespace std;

int city[5001][5001];
int N;

void input()
{
	cin>>N;
	for(int i = 1; i <= N;++i)
	{
		for(int j = i;j<=N;++j)
		{
			if(i == j)city[i][j] =0;
			else{
				city[i][j] = INF;
				city[j][i] = INF;
			}
		}
	}
	int tmp = N-1,a,b;
	while(tmp--){
		cin>>a>>b;
		city[a][b] = 1;
		city[b][a] = 1;
	}
}


int solve()
{
	int ret = INF;
	for(int k = 1;k<=N;++k)
	{
		for(int i = 1;i<=N;++i)
		{
			for(int j = i+1; j <= N;++j){
				int tmp = city[i][k]+city[k][j];
				if(city[i][j] > tmp){
					city[i][j] = tmp;
					city[j][i] = tmp;
				}
			}
		}
	}
	for(int i = 1; i <= N;++i)
	{
		int mx = 0;
		for(int j = 1;j<=N;++j)
		{
			if(city[i][j] != INF &&city[i][j] > mx){
				mx = city[i][j];
			}
		}
		if(ret> mx){
			ret = mx;
		}
	}
	return ret;
}

int main()
{
	int TC=1,T;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	for(;TC<=T;++TC){
		input();
		cout<<'#'<<TC<<' '<<solve()<<'\n';
	}
	return 0;
}