/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : 
summary : 사전순 비교
*/
#include <iostream>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
constexpr int A = 'a'-'A';

string TransForm(string res,string tmp){
  int rl = res.length();
  int tl = tmp.length();
  int l;
  char rc,tc;
  if(rl <= tl){
    for(int i = 0 ; i < rl;i++){
      rc = res[i];
      tc = tmp[i];
      if(rc < 'a')rc+=A;
      if(tc < 'a')tc+=A;
      if(rc != tc){
        if(rc < tc){
          return res;
        }
        else {
          return tmp;
        }
      }
    }
    return res;
  }
  else{
    for(int i = 0 ; i <tl;i++){
      rc = res[i];
      tc = tmp[i];
      if(rc < 'a')rc+=A;
      if(tc < 'a')tc+=A;
      if(rc != tc){
        if(rc < tc){
          return res;
        }
        else {
          return tmp;
        }
      }
    }
    return tmp;
  }
}

int main() {
  io;
  int n;string res;
  while(cin>>n){
    if(n == 0)break;
    cin>>res;
    string tmp;
    Loop(i,1,n){
      cin>>tmp;
      res = TransForm(res,tmp);
    }
    cout<<res<<endl;
  }
}