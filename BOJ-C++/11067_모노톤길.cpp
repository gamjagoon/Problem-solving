/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/11067
summary : 그리디
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
//Global
struct xy{int x,y;};
vector<xy>res;
int N;

void init(){
  res.clear();
  res.push_back({-1,0});
  cin>>N;
  int t = N;
  int x,y;
  while(t--){
    cin>>x>>y;
    res.push_back({x,y});
  }
  sort(res.begin(),res.end(),[](const xy &A,const xy &B){
    if(A.x == B.x){
      return A.y < B.y;
    }else{
      return A.x < B.x;
    }
  });
}

void solve(){
  for(int i = 1; i <= N; i++){
    if(res[i-1].x != res[i].x){
      int l = i;
      int r = i;
      while(r <= N){
        if(res[l].x != res[r].x)break;
        r++;
      }
      if(res[i-1].y!=res[l].y){
        reverse(res.begin() + l, res.begin() + r);
      }
    }
  }
  int m;
  cin>>m;
  int a;
  Loop(i,0,m){
    cin>>a;
    cout<<res[a].x<<' '<<res[a].y<<endl;
  }
}

int main() {
  io;
  int tc;cin>>tc;
  while (tc--)
  {
    init();
    solve();
  }
}