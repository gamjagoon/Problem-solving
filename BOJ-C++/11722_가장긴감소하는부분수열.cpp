/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/11722
summary : 다이나믹 프로그래밍
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
int N,cur,res = 1;
int Dp[1001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  while(N--){
    cin>>cur;
    int j = 1;
    while(1){
      if(Dp[j] != 0 && Dp[j] > cur){
        j++;
      }else{
        Dp[j] = cur;
        break;
      }
    }
    res = res > j ? res : j;
  }
  cout<<res;
}