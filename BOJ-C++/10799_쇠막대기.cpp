
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : 구현
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  string input;
  int cnt = 0,st = 0;
  bool flag = false;
  cin>>input;
  for(auto c :input){
    if(c == '('){
      ++st;
      flag = true;
    }else{
      --st;
      if(flag){
        cnt += st;
        flag = false;
      }else {
        cnt++;
      }
    }
  }
  cout<<cnt;
}