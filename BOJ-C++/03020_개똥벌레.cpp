/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : Dp
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
//Global
int t_b[500002];
int t_t[500002];
int H,result,cnt = 1;

int main() {
  io;
  int n;
  cin>>n>>H;
  n/=2;
  for(int i = 0;i < n;i++){
    int b,t;
    cin>>b>>t;
    t_b[b]++;    
    t_t[t]++;
  }
  result = n;
  for(int h = 1; h < H; h++){
    n -= t_b[h];
    n += t_t[H-h];
    if(result > n){
      result = n;
      cnt = 1;
    }else if (result == n){
      cnt++;
    }
  }
  
  cout<<result<<' '<<cnt;
  return 0;
}