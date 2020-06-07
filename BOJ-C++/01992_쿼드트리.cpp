/*
Date : 06/03/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1992
summary : 분할 정복
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
char arr[65][65];
int N;

pair<bool,char>qurd(int rs,int cs,int offset) {
  char ret = arr[rs][cs];
  int re = rs + offset;
  int ce = cs + offset;
  for(int r = rs; r < re; r++){
    for(auto c = cs; c < ce; c++){
      if(ret != arr[r][c])return make_pair(false,ret);
    }
  }
  return make_pair(true,ret);
}

string solve(int rs,int re,int cs, int ce){
  string ret = "";
  int offset = re-rs + 1;
  if(offset == 1){
    ret.push_back(arr[rs][cs]);
    cout<<"return "<<ret<<endl;
    return ret;
  }
  auto[isqurd, c] = qurd(rs,cs,offset);
  if(isqurd){
    ret.push_back(c);
    cout<<"return "<<ret<<endl;
    return ret;
  }
  int cm = (cs + ce)/2;
  int rm = (rs + re)/2;
  ret = "(" + solve(rs,rm,cs,cm) + solve(rs,rm,cm+1,ce) + solve(rm+1, re,cs,cm) + solve(rm+1,re,cm+1,ce) + ")"; 
  return ret;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for (int i = 0 ; i < N; i++) {
    cin>>arr[i];
  }
  cout<<solve(0,N-1,0,N-1);
}
