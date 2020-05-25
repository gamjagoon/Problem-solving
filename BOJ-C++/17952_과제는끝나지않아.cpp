/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : math
*/
#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

struct STD{
  int val,t;
};

//Global
int N;
int res = 0;
stack<STD>save;
STD cur;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  int a,A,T;
  for(int i = 0; i < N; i++){
    cin>>a;
    if(a == 0){
      if(cur.t == 0){
        if(!save.empty()){
          cur= save.top();
          save.pop();
          cur.t--;
          if(cur.t == 0){
            res+=cur.val;
            cur.val = 0;
          }
        }else{
          continue;
        }
      }
      else if(cur.t == 1){
        res+=cur.val;
        cur.t = 0;
        cur.val = 0;
      }else{
        cur.t--;
      }
    }else{
      cin>>A>>T;
      if(cur.t == 0){
        cur.val = A;
        cur.t = T-1;
        if(cur.t == 0){
          res += cur.val;
          cur.t = 0;
          cur.val = 0;
        }
      }else {
        save.push(cur);
        cur.val = A;
        cur.t = T-1;
        if(cur.t == 0){
          res += cur.val;
          cur.t = 0;
          cur.val = 0;
        }
      }
    }
  }
  cout<<res;
}