/*
Date : 05/19/2020
version : gcc 9.2.0 c++17
problem : 
summary : stack
*/
#include <iostream>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
int st[100001];
int cur = -1;
int res = 0;
//Global

void push(int n){
  st[++cur] = n;
}
void pop(){
  cur--;
}

int top(){
  if(cur ==-1)return 0;
  return st[cur];
}

int main(){
  io;
  int K;cin>>K;
  while(K--){
    int tmp;cin>>tmp;
    if(tmp){
      push(tmp);
      res+=tmp;
    }else{
      res-=top();
      pop();
    }
  }
  if(cur == -1){
    cout<<0;
  }
  else {
    cout<<res<<endl;
  }
}