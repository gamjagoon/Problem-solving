/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/16460
summary : 구현
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
vector<string>res;
string a;
int b;

int main() {
  io;
  string tmp;
  cin>>tmp>>a>>b;
  int t;cin>>t;
  while(t--){
    string name;
    string n;
    int v;
    cin>>name>>n>>v;
    if(a.length() > 1){
      if(b >= v){
        res.push_back(name);
      }else {
        continue;
      }
    }
    else if(n.length() > 1){
      if(b >= v){
        res.push_back(name);
      }else {
        continue;
      }
    }
    else if(a == n && v <= b){
      res.push_back(name);
    }
  }
  if(res.size() == 0){
    cout<<"No one yet";
    return 0;
  }
  sort(res.begin(),res.end());
  for(auto &i : res){
    cout<<i<<endl;
  }
}