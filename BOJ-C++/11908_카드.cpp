
/*
Date : 07/05/2020
version : gcc 9.2.0 c++17
problem : 
summary : implement
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global


int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  int res = 0,M=-1,K;
  while(N--){
    cin>>K;
    res += K;
    M = M < K ? K : M;
  }
  cout<<res - M;
}