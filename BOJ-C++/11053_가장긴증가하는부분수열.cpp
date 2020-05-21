/*
Date : 05/19/2020
version : gcc 9.2.0 c++17
problem : 
summary : Dp
*/
#include <iostream>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int DP[1002];
int res = 1;

int main() {
  io;
  int k;cin>>k;
  while (k--)
  {
    int tmp;cin>>tmp;
    int i = 1;
    for(;DP[i] != 0&&DP[i]<tmp;i++){
    }
    res = res > i ? res : i;
    DP[i] = tmp;
  }
  cout<<res;
}