/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/10039
summary : 구현
*/
#include <iostream>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
//Global

int main() {
  int total = 0;
  int tmp;
  int t = 5;
  while(t--){
    cin>>tmp;
    if(tmp < 40)tmp = 40;
    total += tmp;
  }
  cout<<total/ 5;
}