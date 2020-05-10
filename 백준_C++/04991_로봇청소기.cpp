/*
Date : 05/09/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/4991
summary : 최단경로 문제제
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
constexpr int INF = 1000000009;
using namespace std;

struct P
{
  int r,c;
};
P list[11];
int dist[11][11];
char arr[21][21];
bool visit[21][21];
//Global
int R,C;
int N;
int sr,sc;
int Result;

void input() 
{
  Loop(r,0,R){
    cin>>arr[r];
  }
  N = 0;
  Loop(r,0,R){
    Loop(c,0,C){
      if(arr[r][c] == '*'){
        list[++N] = {r,c};
      }else if(arr[r][c] == 'o'){
        sr = r;
        sc = c;
        list[0] = {r,c};
      }
    }
  }
}

int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

bool OutRange(int r, int c){
  return r < 0 || c < 0 || r >= R || c >= C;
}

void CalDistance(int st,int ed){
  auto[edr,edc] = list[ed];
  Loop(r,0,R){
    Loop(c,0,C){
      visit[r][c] = false;
    }
  }
  queue<P>q;q.push(list[st]);
  visit[list[st].r][list[st].c] = true;
  int cnt = 0;
  while(!q.empty()){
    int sz = q.size();
    for(int s = 0; s < sz; ++s){
      auto[r,c]  = q.front();q.pop();
      if(r == edr && c ==edc){
        dist[st][ed] = cnt;
        dist[ed][st] = cnt;
        return;
      }
      for(auto d = 0; d < 4; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(OutRange(nr,nc) || visit[nr][nc] || arr[nr][nc] == 'x')continue;
        visit[nr][nc] = true;
        q.push({nr,nc});
      }
    }
    cnt++;
  }
  dist[st][ed] = INF;
  dist[ed][st] = INF;
}

bool check_end(){
  Loop(r,0,N+1){
      Loop(c,0,N+1){
        if(dist[r][c] == INF){
          return true;
        }
      }
  }
  return false;
}

int calc_res(vector<int>&a){
  int res = 0;
  int s = 0;
  for(auto &i : a){
    res += dist[s][i];
    s = i;
  }
  return res;
}

void permu(vector<int>&a,int SetSize,int n){
  if(SetSize == n){
    int ret = calc_res(a);
    Result = ret < Result ? ret : Result;
    return;
  }
  for(int i = SetSize; i < n;i++){
    swap(a[i],a[SetSize]);
    permu(a,SetSize+1,n);
    swap(a[i],a[SetSize]);
  }
}

void solve(){
  vector<int>s;
  for(int i = 1; i <= N;i++){
    s.push_back(i);
  }
  permu(s,0,N);

}

int main() {
  io;
  while(1){
    cin>>C>>R;
    if(R == 0){
      break;
    }
    input();
    for(int i = 0; i <= N; ++i){
      for(int j = i + 1; j <= N;++j){
        CalDistance(i,j);
      }
    }
    if(check_end()){
      cout<<-1<<endl;
      continue;
    }
    Result = INF;
    solve();
    cout<<Result<<endl;
  }
}
