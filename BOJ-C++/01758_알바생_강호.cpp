/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : 
summary : 그리디
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int n;
vector<int>v;

int main() {
  io;cin>>n;
  v.resize(n);
  for(auto &i : v)cin>>i;
  sort(v.begin(),v.end(),[](int a,int b){return a > b;});
  long long res = 0;
  Loop(i,1,n+1){
    int tmp = v[i-1]-(i - 1);
    if(tmp < 0)tmp = 0;
    res += tmp;
  }
  cout<<res;
}