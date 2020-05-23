/*
Date : 05/23/2020
version : gcc 9.2.0 c++17
problem : 
summary : count
*/
#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
typedef long long ll;
//Global
ll N,Q;
map<ll,ll>T;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>Q;
  ll tmp;
  long long s = 0;
  T.insert({s,1});
  for(ll i = 1; i <= N; i++){
    cin>>tmp;
    s += tmp;
    T.insert({s,i+1});
  }
  long long query;
  for(ll i = 0; i < Q; i++){
    cin>>query;
    cout<<(*T.upper_bound(query)).second-1<<endl;;
  }
}