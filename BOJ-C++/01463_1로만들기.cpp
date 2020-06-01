
/*
Date : 06/01/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1463
summary : DP
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
int N;
int dp[1000000];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  dp[1] = 0;
  for(int i = 2; i <= N; i++){
    dp[i] = dp[i-1] + 1;
    if(i%2 == 0){
      dp[i] = min(dp[i],dp[i/2]+1);
    }
    if(i % 3 == 0){
      dp[i] = min(dp[i],dp[i/3] + 1);
    }
  }
  cout<<dp[N];
}