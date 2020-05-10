/*
Date : //2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/9658
summary : 다이나믹 프로그래밍 
*/
#include <iostream>
#include <bitset>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int num;
bitset<1001>dp;
int main()
{
  io;
  cin>>num;
  dp[1]=dp[3]=true;
  Loop(i,4,num+1){
    if(!dp[i-1] && !dp[i-3] && !dp[i-4])dp[i]=true;
  }
  if(dp[num]){
    cout<<"CY";
  }else{
    cout<<"SK";
  }
  return 0;
}