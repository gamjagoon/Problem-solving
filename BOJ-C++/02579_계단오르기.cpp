
/*
Date : 06/01/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/2579
summary : dp
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
int N;
int point[301];
int dp[301];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(size_t i = 1; i <= N;i++){
    cin>>point[i];
  }
  dp[1] = point[1];
  dp[2] = max(dp[1]+point[2],point[2]);
  for(auto i = 3; i <= N;i++){
    dp[i] = max(dp[i-2] + point[i],dp[i-3] + point[i] + point[i-1]);
  }
  cout<<dp[N];
}