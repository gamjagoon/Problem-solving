
/*
Date : 06/11/2020
version : gcc 9.2.0 c++17
problem : 
summary : 최소스패닝트리
*/
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

typedef long long ll;
//Global
constexpr int M_Node = 10001;
constexpr ll offset = 1000000;
struct node{
  ll cost;
  int t;
};

struct cmp{
  bool operator()(node& a,node& b){
    if(a.cost != b.cost){
      return a.cost > b.cost;
    }
    return a.t > b.t;
  }
};

int V,E;
bool visit[M_Node];
vector<node> arr[M_Node];

void prim(int start) {
  visit[start] = true;

  priority_queue<node,vector<node>,cmp>pq;

  for(auto i : arr[start]){
    pq.push(i);
  }
  ll ans = 0, cnt = 0;
  while(!pq.empty()){
    int cur = pq.top().t;
    ll curcost = pq.top().cost;

    pq.pop();
    if(visit[cur])continue;

    visit[cur] = true;

    ans += curcost;
    cnt++;
    for(auto i : arr[cur]){
      pq.push(i);
    }
  }
  ans -= cnt * offset;
  cout<<ans;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>V>>E;
  int a,b;
  ll c;
  while(E--){
    cin>>a>>b>>c;
    c+=offset;
    arr[a].push_back({c,b});
    arr[b].push_back({c,a});
  }

  prim(1);
}