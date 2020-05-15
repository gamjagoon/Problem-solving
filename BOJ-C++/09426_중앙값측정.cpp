/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/9426
summary : 멀티셋을 이용한 이진트리 구현 및 이진탐색
*/
#include <iostream>
#include <set>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
//Global
multiset<ll>l,r;
ll N,K,result = 0;
ll list[250001];

void valence_insert(ll prev,ll cur){
  if(prev < cur){
    r.insert(cur);l.insert(prev);
  }else{
    r.insert(prev);l.insert(cur);
  }
}

ll lpop(){
  ll ret{*(--(l.end()))};
  l.erase((--(l.end())));
  return ret;
}

ll rpop(){
  ll ret{*r.begin()};
  r.erase(r.begin());
  return ret;
}

void insert_num(ll cur){
  ll prev;
  if(l.empty()){
      if(r.empty())l.insert(cur);
      else {
        prev = rpop();
        valence_insert(prev,cur);
      }
  }else if(r.empty()){
      prev = lpop();
      valence_insert(prev,cur);
  }
  else {
      if(l.size() <= r.size()){
        prev = rpop();
      }else {
        prev = lpop();
      }
      valence_insert(prev,cur);
  }
}


int main() {
  io;cin>>N>>K;
  if(K == 1){
    ll tmp;
    for(int i = 0; i < N;i++){
      cin>>tmp;
      result += tmp;
    }
  }
  else {
    for(int i = 0; i < N;i++){
      cin>>list[i];
    }
    int i = 0;
    //insert
    for(; i<K ;i++){
      ll cur = list[i];
      insert_num(cur);
    }
    //solve
    result += *(--(l.end()));
    for(;i < N;i++){
      if(*r.begin() <= list[i-K]){
        r.erase(r.find(list[i-K]));
      }
      else l.erase(l.find(list[i-K]));
      
      ll cur = list[i];
      insert_num(cur);
      result += *(--(l.end()));
    }
  }
  cout<<result;
}