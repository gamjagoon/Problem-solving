
/*
Date : 06/06/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1520
summary : DP
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;

//Global
int arr[500][500];
ll dp[500][500];
bool ch[500][500];
int R,C;
int dir[4][2] = {
  1,0,-1,0,0,1,0,-1
};

ll dfs(int r,int c){
  if(r == R-1 && c == C-1){
    return 1;
  }
  if(ch[r][c])return dp[r][c];
  ch[r][c] = true;
  for(int d = 0; d < 4; d++){
    int nr = r + dir[d][0];
    int nc = c + dir[d][1];
    if(nr < 0 || nc < 0 || R <= nr || C <= nc){
      continue;
    }
    if(arr[r][c] > arr[nr][nc]){
      dp[r][c] += dfs(nr,nc);
    }
  }
  return dp[r][c];
}


int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>R>>C;
  for(auto r = 0; r < R; r++){
    for(auto c = 0; c < C; c++){
      cin>>arr[r][c];
    }
  }
  cout<<dfs(0,0);
}