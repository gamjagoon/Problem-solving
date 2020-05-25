/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : Dp
*/
#include <iostream>

#define endl '\n'
using namespace std;

constexpr unsigned int mo = 1000000007;

//Global
unsigned int n,m;
unsigned int res;
unsigned int Dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  if(n > m)swap(n,m);
  for(int i = 1; i <= n;i++){
    Dp[1][i] = 1;
    Dp[i][1] = 1;
  }
  for(int i = n+1;i <= m;i++){
    Dp[1][i] = 1;
  }
  for(int r = 2; r <= n;r++){
    for(int c = 2; c <= m;c++){
      Dp[r][c] = (Dp[r-1][c]%mo + Dp[r][c-1]%mo + Dp[r-1][c-1]%mo)%mo;
    }
  }
  cout<<Dp[n][m]%mo;
}