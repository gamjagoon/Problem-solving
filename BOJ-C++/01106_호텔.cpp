/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1106
summary : BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
struct P{int val,n;};
vector<P>cost;
//Global
int C,N;
int result = 1<<9+9;
int dp[2000];

int main() {
  io;
  cin>>C>>N;
  cost.resize(N);
  queue<P>q;
  for(auto &j :cost){
    cin>>j.val>>j.n;
    dp[j.n] = j.val;
    q.push(j);
  }
  while(!q.empty()){
    P cur = q.front();q.pop();
    if(cur.n >= C){
      result = result < cur.val ? result: cur.val;
      continue;
    }
    for(auto i :cost){
      P Nt{cur.val + i .val, cur.n + i.n};
      if(dp[Nt.n] == 0 || dp[Nt.n] > Nt.val){
        dp[Nt.n] = Nt.val;
        q.push(Nt);
      }
    }
  }
  cout<<result;
}