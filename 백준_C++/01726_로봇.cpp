/*
Date : //2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1726
summary : 구현
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

struct rct
{
  int r,c,t,cnt;
};

//Global
bool arr[101][101];
int visit[101][101][5];
int R,C;
int er,ec,et;
queue<rct>q;

int dir[5][2] = {
0,0,0,1,0,-1,1,0,-1,0
};

// dir left 0 right 1 0 r 1 c
int turn[5][2] ={
 {0,0},{4,3},{3,4},{1,2},{2,1}
};

bool OutRange(int r, int c){
  return r < 1 || c < 1 || R < r|| C < c;
}

void input() {
  cin>>R>>C;
  Loop(r,1,R+1){
    Loop(c,1,C+1){
      cin>>arr[r][c];
    }
  }
  cin>>er>>ec>>et;
  visit[er][ec][et] = true;
  q.push({er,ec,et,0});
  cin>>er>>ec>>et;
}

int solve(){
  int ret = 9999999;
  while(!q.empty()){
      rct cur = q.front();q.pop();
      if(cur.r == er && cur.c == ec && cur.t == et){ 
        ret = ret < cur.cnt ? ret : cur.cnt;
        continue;
      }
      //지금 보는 방향 전진
      int k = 1;
      while(k <= 3){
        int nr = cur.r + dir[cur.t][0] * k;
        int nc = cur.c + dir[cur.t][1] * k;
        k++;
        if(OutRange(nr,nc) || arr[nr][nc] )break;
        int ncnt = cur.cnt + 1;
        if(visit[nr][nc][cur.t]){
          if(!ncnt || visit[nr][nc][cur.t] <= ncnt) continue;
        }
        visit[nr][nc][cur.t] = ncnt;
        q.push({nr,nc,cur.t,cur.cnt+1});
      }
      for(int i = 0 ; i < 2; ++i){
        int nt = turn[cur.t][i];
        if(visit[cur.r][cur.c][nt])continue;
        visit[cur.r][cur.c][nt] = true;
        q.push({cur.r,cur.c,nt,cur.cnt+1});
      }
  }
  return ret;
}

int main() {
  io;
  input();
  cout<<solve();
}