/*
Date : 05/21/2020
version : gcc 9.2.0 c++17
problem : 
summary : BFS
*/
#include <iostream>
#include <queue>
#include <array>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
typedef array< array<bool,101>,101> Type;
//Global
//R G B
int cnt[3];
char arr[101][101];
Type one;
Type two;
int N;
int cnt_one = 0;
int cnt_two = 0;

bool out_rage(int r,int c){
  return r < 0 || c < 0|| r >= N|| c >= N;
}

struct rc{
  int r,c;
};

int dir[4][2]={
  1,0,-1,0,0,1,0,-1
};

void bfs(int R,int C,Type& ch){
  queue<rc>q;
  q.push({R,C});
  ch[R][C] = true;
  char com = arr[R][C];
  while(!q.empty()){
    int r = q.front().r;
    int c = q.front().c;
    q.pop();
    for(int d = 0 ; d < 4; d++){
      int nr = r + dir[d][0];
      int nc = c + dir[d][1];
      if(out_rage(nr,nc) || ch[nr][nc])continue;
      if(arr[nr][nc] == com){
        ch[nr][nc] = true;
        q.push({nr,nc});
      }
    }
  }
}

int main() {
  io;
  cin>>N;
  Loop(i,0,N){
    cin>>arr[i];
  }
  for(int i = 0; i < N;i++){
    for(int j = 0; j < N;j++){
      if(!one[i][j]){
        cnt_one++;
        bfs(i,j,one);
      }
    }
  }
  for(int i = 0; i < N;i++){
    for(int j = 0; j < N;j++){
      if(arr[i][j] == 'G'){
        arr[i][j] = 'R';
      }
    }
  }
  for(int i = 0; i < N;i++){
    for(int j = 0; j < N;j++){
      if(!two[i][j]){
        
        cnt_two++;
        bfs(i,j,two);
      }
    }
  }
  cout<<cnt_one<<' '<<cnt_two;
}