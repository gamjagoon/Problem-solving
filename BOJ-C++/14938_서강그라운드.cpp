#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;
typedef struct le{
	int l,e;
}le;
struct cmp{
	bool operator()(le &a, le &b){
		return a.l > b.l;
	}
};
//Global

int N,M,r;
array<array<int,101>, 101>dist;
array<int,101>arr;
vector<le>g[101];

int solve(int s){
	priority_queue<le,vector<le>,cmp>pq;
	pq.push({0,s});
	for(int i = 1 ; i <= N;++i)dist[s][i] = INF;
	dist[s][s] = 0;
	while (!pq.empty()) {
		le curr = pq.top();
		pq.pop();
		if(dist[s][curr.e] < curr.l)continue;

		for(auto next : g[curr.e]){
			int cost = curr.l + next.l;
			if(dist[s][next.e] > cost){
				dist[s][next.e] = cost;
				pq.push({cost,next.e});
			}
		}
	}
	int ret = 0;
	for(int i = 1; i <= N; ++i){
		if(dist[s][i] <= M){
			ret += arr[i];
		}
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>M>>r;
	for(int i = 1; i <= N;++i){
		cin>>arr[i];
	}
	int s,e,l;
	while(r--){
		cin>>s>>e>>l;
		g[s].push_back({l,e});
		g[e].push_back({l,s});
	}
	int res = 0;
	for(int i = 1; i <= N;++i){
		int ret = solve(i);
		res = max(res,ret);
	}
	cout<<res;
}
