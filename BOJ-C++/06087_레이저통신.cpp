/*
Date : 05/28/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/6087
summary : BFS
*/
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

//Global
struct rc{
  int r,c;
};

char arr[100][100];
bool ch[100][100][4];
int R,C;
rc se[2];
int dir[4][2] = {
1,0,-1,0,0,1,0,-1
};

inline void chpoint(rc &a,int d){
  ch[a.r][a.c][d] = true;
}

bool Out_range(rc &a){
  return a.r < 0 || a.c < 0 || a.r >= R || a.c >= C;
}

void bfs(int &ret){
  queue<pair<rc,int>>q;
  for(int i = 0; i < 4; i++){
    q.push({se[0],i});
    chpoint(se[0],i);
  }
  rc cur,nxt;
  int d,p;
  while(!q.empty()){
    int sz = q.size();
    for(int i = 0 ; i < sz;i++)
    {
      cur = q.front().first;
      d = q.front().second;q.pop();
      p = 1;
      while(1){
        nxt = {cur.r + dir[d][0]*p,cur.c + dir[d][1]*p};
        if(Out_range(nxt) || arr[nxt.r][nxt.c] == '*' || ch[nxt.r][nxt.c][d])break;
        if(nxt.r == se[1].r && nxt.c == se[1].c)return;
        chpoint(nxt,d);
        for(int j = 0; j < 4; j++){
          q.push({nxt,j});
        }
        p++;
      }
    }
    ret++;
  }
  
}


int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>C>>R;
  for(int r = 0,i = 0; r < R; r++){
    for(int c = 0; c < C; c++){
      cin>>arr[r][c];
      if(arr[r][c] == 'C'){
        se[i++] = {r,c};
      }
    }
  }
  int res = 0;
  bfs(res);
  cout<<res;
}