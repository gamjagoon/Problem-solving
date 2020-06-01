
/*
Date : 06/01/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/17608
summary : 구현
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
int N;
int H[100001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(auto i = 0; i < N; i++){
    cin>>H[i];
  }
  int res = 1;
  int prev = H[N-1];
  for(auto i = N-2; i >= 0; i--){
    if(H[i] > prev){
      //current height higher than prev
      prev = H[i];
      res++;
    }
  }
  cout<<res;
}