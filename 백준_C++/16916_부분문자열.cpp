/*
Date : 05/07/2020
version : gcc 9.2.0 c++17
problem : 
summary : KMP
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
string par;
string chile;

vector<int>getPi(const string S){
  int m = (int)S.size(),j = 0;
  vector<int>ret(m,0);
  for(int i = 1; i < m;i++){
    while(j > 0 && S[i] != S[j]){
      j = ret[j-1];
    }
    if(S[i] == S[j]){
      ret[i] = ++j;
    }
  }
  return ret;
}


int main(){
  io;
  cin>>par;
  int par_len = (int)par.size();
  cin>>chile;
  int chile_len = (int)chile.size();
  vector<int>Pi = getPi(chile);
  int j = 0;
  for(int i = 0 ; i < par_len;++i){
    while(j > 0 && par[i] != chile[j]){
      j = Pi[j-1];
    }
    if(par[i] == chile[j]){
      if(j == chile_len-1){
        cout<<1;
        return 0;
      }
      else{
        j++;
      }
    }
  }
  cout<<0;
  return 0;
}