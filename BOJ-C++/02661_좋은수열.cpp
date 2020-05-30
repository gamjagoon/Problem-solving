/*
Date : 05/28/2020
version : gcc 9.2.0 c++17
problem : 
summary : 빽트레킹
*/
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
int N;
//Global
string ret= "";
string res;
string A,B;
bool E = false;

bool issafe(int n){
  int sz = n / 2;
  int s = n - 1;
  for(int i = 1; i <= sz;i++){
    A = ret.substr(s-i,i);
    B = ret.substr(n-i,i);
    if(A == B){
      return false;
    }
    s--;
  }
  return true;
}

void dfs(int n){
  if(E)return;
  if(issafe(n)){
    if(n == N){
      res = ret;
      E = true;
      return ;
    }else{
      for(char i = '1'; i < '4'; i++){
        ret.push_back(i);
        dfs(n+1);
        ret.pop_back();
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  dfs(0);
  cout<<res;
}