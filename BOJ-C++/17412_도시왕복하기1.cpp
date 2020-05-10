#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global

int N,P;
int C[401][401];
int F[401][401];
int W[401][401];
int dist[401],Prev[401];
bool ch[401];
vector<int>g[401];

int solve()
{
	int total= 0;
	int min_cost = 0;
	while(1)
	{
		queue<int>q;
		fill(Prev,Prev+401,-1);
		fill(dist,dist+401, INF);

		ch[1] = true;
		dist[1] = 0;
		q.push(1);
		while(!q.empty())
		{
			int qs = q.size();
			while(qs--)
			{
				int curr = q.front();
				q.pop();
				ch[curr] = false;
				for(auto nt : g[curr]){
					if(C[curr][nt] - F[curr][nt] > 0  && dist[nt] > dist[curr] + W[curr][nt])
					{
						dist[nt] = dist[curr] + W[curr][nt];
						Prev[nt] = curr;
						if(!ch[nt])
						{
							ch[nt] = true;
							q.push(nt);
							if(nt == 2)break;
						}
					}
				}
			}
		}
		if(Prev[2] == -1)break;
		int flow = INF;
		for(int i = 2; i != 1; i = Prev[i]){
			flow = min(flow,C[Prev[i]][i] - F[Prev[i]][i]);
		}

		for(int i = 2; i != 1; i = Prev[i]){
			min_cost += flow * W[Prev[i]][i];
			F[Prev[i]][i] += flow;
			F[i][Prev[i]] -= flow;
		}
	++total;
	}
	return total;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>P;
	int s,e;
	while(P--){
		cin>>s>>e;

		g[e].push_back(s);
		g[s].push_back(e);

		W[s][e] = 1;
		W[e][s] = -1;

		C[s][e] = 1;
	}
	cout<<solve();
}
