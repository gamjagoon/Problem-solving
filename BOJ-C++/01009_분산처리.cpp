/*
Date : 05/19/2020
version : gcc 9.2.0 c++17
problem : 
summary : 수학
*/
#include <iostream>

#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
constexpr int M = 10;
int main() {
  io;
  int T;cin>>T;
  while(T--){
    int a,b;
    cin>>a>>b;
    int res = 1;
    Loop(i,0,b){
      res = (res * a )%10;
    }
    if(res == 0)cout<<10;
    else cout<<res;
    cout<<"\n";
  }
}