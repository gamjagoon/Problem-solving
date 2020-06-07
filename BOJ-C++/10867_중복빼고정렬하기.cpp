
/*
Date : 06/01/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/10867
summary : set
*/
#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

set<int>input;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int t;cin>>t;
  int tmp;
  while(t--){
    cin>>tmp;
    input.insert(tmp);
  }
  for(auto j : input){
    cout<<j<<' ';
  }
}