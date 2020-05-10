
/*
Date : 05/06/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1743
summary : DFS
*/
#include <iostream>
#include <array>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int R,C,N;
array< array<bool,102>, 102>trash;
array< array<bool,102>, 102>ch;
array<int,10001>sz;
int cnt = 0;
int res = 0;
int dir[4][2]={
  1,0,-1,0,0,1,0,-1
};

void InputData(int N){
  int r, c;
  Loop(i,0,N){
    cin>>r>>c;
    trash[r][c] = true;
  }
}

bool OutRange(int r,int c){
  return R < r || C < c || r < 1 || c < 1;
}

void put_in(int r,int c,int cnt){
  sz[cnt]++;
  ch[r][c] = true;
  for(auto d = 0; d < 4;++d){
    int nr = r + dir[d][0];
    int nc = c + dir[d][1];
    if(OutRange(nr,nc) || !trash[nr][nc] || ch[nr][nc])continue;
    put_in(nr,nc,cnt);
  }
}

int main(){
  io;
  cin>>R>>C>>N;
  InputData(N);
  Loop(r,1,R+1){
    Loop(c,1,C+1){
      if(trash[r][c] && !ch[r][c]){
        cnt++;
        put_in(r,c,cnt);
      }
      if(res < sz[cnt])res = sz[cnt];
    }
  }
  cout<<res<<endl;
}
