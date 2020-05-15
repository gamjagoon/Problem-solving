/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1701
summary : KMP
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global

string input;

int make_table(int length) {
  int ret = 0;
  Loop(k,0,length){
    string tmp = input.substr(k,length);
    vector<int>pi(tmp.length());
    int j = 0;
    Loop(i,1,tmp.length()){
      while(j > 0 && tmp[i] != tmp[j]){
        j = pi[j-1];
      }
      if(tmp[i] == tmp[j]){
        pi[i] = ++j;
        ret = max(ret,pi[i]);
      }
    }
  }
  return ret;
}

int main() {
  io;
  cin>>input;
  cout<<make_table(input.size());
}