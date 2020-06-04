
/*
Date : 06/04/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1987
summary : 빽트렉킹 -> DFS 이용
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
int R,C;
char arr[20][20];
bool ch[255];
int res = 1;

int dir[4][2] ={
  1,0,-1,0,0,1,0,-1
};

bool out_range(int r,int c){
  return r < 0 || c < 0 || R <= r || C <= c;
}

void dfs(int r,int c,int cnt){
  res = res < cnt ? cnt : res;
  for(int d = 0; d < 4; d++){
    int nr = r + dir[d][0];
    int nc = c + dir[d][1];
    if(out_range(nr,nc) || ch[arr[nr][nc]]){
      //out_range and double check 
      continue;
    }
    ch[arr[nr][nc]] = true;
    dfs(nr,nc,cnt+1);
    ch[arr[nr][nc]] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>R>>C;
  for(auto r = 0; r < R; r++){
    for(auto c = 0; c < C; c++){
      cin>>arr[r][c];
    }
  }
  ch[arr[0][0]] = true;res = 1;
  dfs(0,0,1);
  cout<<res;
}