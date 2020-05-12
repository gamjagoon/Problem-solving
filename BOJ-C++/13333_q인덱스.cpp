/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/13333
summary : 구현
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
vector<int>v;

int main() {
  io;
  int n;cin>>n;
  v.resize(n);
  for(auto &i : v){
    cin>>i;
  }
  int res = 0;
  for(int i = n; i >= 0; i--){
    int up = 0;
    int down = 0;
    for(auto j : v){
      if(j >= i)up++;
      else down++;
    }
    if(up >= i && down <= (n - i)){
      res = i;
      break;
    }
  }
  cout<<res;
}
