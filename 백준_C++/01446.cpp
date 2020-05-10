/*
Date : 05/09/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1446
summary : dfs
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0)
using namespace std;

struct P{
  int e,c;
};
int N,L;
// start,end, cost
vector<P> arr[10001];
int ch[10001];
int res = 10001;

void dfs(int p,int cost){
  if(p > L)return;
  if(p == L){
    res = cost < res ? cost : res;
    return;
  }
  if(arr[p].size()){
    for(auto i : arr[p])
    {
      int next_cost = cost+i.c;
      if(ch[i.e] == 0 || next_cost < ch[i.e]  ){
        ch[i.e] = next_cost;
        dfs(i.e,next_cost);
      }
    }
  }
  if(ch[p+1] == 0 || cost+1 < ch[p+1]){
    ch[p+1] = cost+1;
    dfs(p+1,cost+1);
  }
}


int main() {
  io;
  cin>>N>>L;
  Loop(i,0,N){
    int s,e,c;
    cin>>s>>e>>c;
    arr[s].push_back({e,c});
  }
  dfs(0,0);
  cout<<res<<endl;
}
