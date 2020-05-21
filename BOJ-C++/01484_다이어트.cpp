/*
Date : 05/21/2020
version : gcc 9.2.0 c++17
problem : 
summary : 수학
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int G;
vector<pair<int,int>>list;
vector<int>res;

int main() {
  io;cin>>G;
  for(int i = 1; i < G;i++){
    if(G % i == 0){
      int tmp = G / i;
      if(tmp <= i){
        break;
      }
      list.push_back({i,tmp});
    }
  }
  for(auto i : list){
    int a = i.first;
    int b = i.second - a;
    if(b % 2 != 0)continue;
    b /= 2;
    res.push_back(a+b);
  }
  if(res.empty()){
    cout<<-1;
  }else{
    sort(res.begin(),res.end());
    for(auto i : res){
      cout<<i<<'\n';
    }
  }
}