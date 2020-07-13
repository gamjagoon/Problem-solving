
/*
Date : 07/13/2020
version : gcc 9.2.0 c++17
problem : 
summary : 규칙찾기
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global


int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int n,p;
  cin>>n>>p;
  if(n == 1){
    cout<<"YES";
  }else if(n == 2){
    if(p == 1){
      cout<<"YES";
    }else cout<<"NO";
  } else if (n == 3){
    if(p == 2)cout<<"YES";
    else
    {
      cout<<"NO";
    }
  } else {
    int s = 0;int e = n+1;
    int l,r;
    int cnt = n;
    while(1){
      --e;--cnt;
      if(cnt == 1){
        l = s+1;break;
      }
      ++s;--cnt;
      if(cnt == 1){
        l = s+1;break;
      }
      --e;--cnt;
      if(cnt == 1){
        l = s+1;break;
      }
    }
    s = 0,e = n+1;
    cnt = n;
    while(1){
      --e;--cnt;
      if(cnt == 1){
        r = s+1;break;
      }
      ++s;--cnt;
      if(cnt == 1){
        r = s+1;break;
      }
      ++s;--cnt;
      if(cnt == 1){
        r = s+1;break;
      }
    }
    if(l >= r){
      int tmp  = l;
      l = r;
      r = tmp;
    }
    if(l <= p && p <= r){
      cout<<"YES";
    }else{
      cout<<"NO";
    }
  }
  return 0;
}