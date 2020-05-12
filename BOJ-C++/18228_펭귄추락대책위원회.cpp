/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/18228
summary : 구현 
*/
#include <iostream>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int lv = 1000000001;

int main() {
  io;
  int t;cin>>t;
  long long res = 0;
  int i = 1;
  while(1){
    int val;cin>>val;
    i++;
    if(val == -1){
      res += lv;
      lv = 1000000001;
      break;
    }else if(val < lv){
      lv = val;
    }
  }
  while(i <= t){
    int val;cin>>val;
    i++;
    if(val < lv){
      lv = val;
    }
  }
  cout<<res + lv;
}
