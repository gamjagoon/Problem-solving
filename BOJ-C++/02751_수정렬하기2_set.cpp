
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : set
*/
#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

//Global
set<int> a;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  int tmp;
  while(N--){
    cin>>tmp;a.insert(tmp);
  }
  for(auto i : a){
    cout<<i<<endl;
  }
}