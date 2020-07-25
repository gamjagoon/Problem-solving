#pragma -O3
/*
Date : 07/18/2020
version : gcc 9.2.0 c++17
problem : 
summary : 
*/
#include <iostream>
#define endl '\n'
using namespace std;

#define INF 1000001

//Global
int st[1000001];
int cur = -1;
int res[1000001];
int input[1000001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  for(int i = 0 ; i < N;i++){
    cin>>input[i];
  }
  if(N == 1){
    cout<<-1;
  } else{
    for(int i = N-1;i >=0 ;--i){
      if(cur == -1){
        res[i] = -1;
      }else{
        if(input[i] < st[cur]){
          res[i] = st[cur];
        }else{
          while(cur >= 0 && st[cur] <= input[i]){
            --cur;
          }
          if(cur < 0)res[i] = -1;
          else{
            res[i] = st[cur];
          }
        }
      }
      st[++cur] = input[i];
    }
    for(int i = 0; i < N;i++){
      cout<<res[i]<<' ';
    }
  }
}