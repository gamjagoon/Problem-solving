/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1162
summary : 다익스트라;
*/
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
constexpr ll INF = (ll(1)<<59)-1;
using namespace std;

//Global
ll N,M,K;

struct ncc{
  ll node,cost,cnt;
  bool operator < (const ncc a)const{
    return cost > a.cost;
  }
};
typedef pair<ll,ll>p;
vector<p>g[10002];
ll dist[10002][21];
ll result = INF;

int main() {
  io;
  cin>>N>>M>>K;
  Loop(i,0,M){
    int a,b,v;
    cin>>a>>b>>v;
    g[a].push_back({b,v});
    g[b].push_back({a,v});
  }
  Loop(i,1,N+1){
    Loop(k,0,K+1){
      dist[i][k] = INF;
    }
  }

  priority_queue<ncc>pq;pq.push({1,0,0});
  dist[1][0] = 0;
  while(pq.size()){
    ll cur = pq.top().node;
    ll cost = pq.top().cost;
    ll cnt = pq.top().cnt;

    pq.pop();
    if(cost > dist[cur][cnt])continue;

    for(auto i : g[cur]){
      ll nxt = i.first;
      ll nxtcost = cost + i.second;
      if (nxtcost < dist[nxt][cnt]){
        dist[nxt][cnt] =nxtcost;
        pq.push({nxt,nxtcost,cnt});
      }
      if(cnt < K && cost < dist[nxt][cnt+1]){
        dist[nxt][cnt+1] = cost;
        pq.push({nxt,cost,cnt+1});
      }
    }
  }
  for(int i = 0 ; i <= K;i++)result = min(result, dist[N][i]);
  cout<<result;
}