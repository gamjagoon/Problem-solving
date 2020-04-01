#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
typedef struct rc{
	int r,c;
	bool operator==(rc &a){
		return r == a.r && c == a.c;
	}
}rc;
typedef struct cmp{
	bool operator()(pair<int,rc>&a,pair<int,rc>&b){
		if(a.first == b.first){
			return a.second.r < b.second.r;
		}
		return a.first > b.first;
	}
}cmp;
int N;
int arr[126][126];
int dist[126][126];
int dir[4][2] = {1,0,-1,0,0,-1,0,1};
bool out_range(rc P){
	return P.r < 0 || P.c < 0|| P.c >= N || P.r >= N;
}

int die(rc e){
	priority_queue<pair<int,rc>,vector<pair<int,rc>>,cmp>pq;
	dist[0][0] = arr[0][0];
	pq.push({dist[0][0],{0,0}});
	while(!pq.empty())
	{
		rc now = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		if(c > dist[now.r][now.c])continue;
		if(now == e)return c;
		rc tmp;
		for(int d = 0 ; d < 4 ; ++d){
			tmp.r = now.r + dir[d][0];
			tmp.c = now.c + dir[d][1];
			if(out_range(tmp))continue;
			int next_cost = c + arr[tmp.r][tmp.c];
			if(dist[tmp.r][tmp.c] > next_cost)
			{
				dist[tmp.r][tmp.c] = next_cost;
				pq.push({next_cost,tmp});
			}
		}
	}
	return INF;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
	while(1){
		cin>>N;if(N == 0 )break;
		for(size_t r = 0 ; r < N; r++){
			for(size_t c = 0; c < N; c++){
				cin>>arr[r][c];
				dist[r][c] = INF;
			}
		}
		cout<<"Problem "<<t<<": "<<die({N-1,N-1})<<endl;
		t++;
	}
}
