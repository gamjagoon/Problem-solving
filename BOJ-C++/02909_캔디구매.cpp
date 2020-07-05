
/*
Date : 07/04/2020
version : gcc 9.2.0 c++17
problem : 
summary : 
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
int dd(int d,int K){
  if(K == 0)return d;
  return dd(d*10,K-1);
}


int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N,K;cin>>N>>K;
  int d = dd(1,K);
  int k = N%d;
  if(k < d/2){
    N -= k;
  }else{
    N -= k;
    N += d;
  }
  cout<<N;
}