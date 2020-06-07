
/*
Date : 06/06/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1091
summary : 시뮬
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
int N,P[48],S[48];

bool correct(){
  for(auto i = 0; i < N; i++){
    if(i%3 != P[i])return false;
  }
  return true;
}

void suffle(){
  int tmp[48];
  for(auto i = 0; i < N; i++){
    tmp[S[i]] = P[i];
  }
  for(auto i = 0; i < N; i++){
    P[i] = tmp[i];
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(auto i = 0; i < N; i++){
    cin>>P[i];
  }
  for(auto i = 0; i < N; i++){
    cin>>S[i];
  }
  int res = 0;
  for(int i = 0; i <= 120119;i++){
    if(correct()){
      cout<<res;
      return 0;
    }
    suffle();
    res++;
  }
  cout<<-1;
}