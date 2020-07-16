
/*
Date : 07/13/2020
version : gcc 9.2.0 c++17
problem : 
summary : 구현 
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
int N;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  int t = N;
  int tmp,cnt = 0,res = 0;
  int M = 0;
  while(t--){
    cin>>tmp;
    if(M < tmp){
      res = cnt > res ? cnt : res;
      cnt = 0;
      M = tmp;
    }else {
      cnt++;
    }
  }
  res = cnt > res ? cnt : res;
  cout<<res;
}