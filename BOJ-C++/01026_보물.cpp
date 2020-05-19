/*
Date : 05/19/2020
version : gcc 9.2.0 c++17
problem : 
summary : 정렬
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
vector<int>a,b;

int main() {
  io;
  int n;cin>>n;
  a.resize(n);b.resize(n);
  for(auto &i:a)cin>>i;
  for(auto &i:b)cin>>i;
  sort(a.begin(),a.end(),[](int l,int r){
    return l < r;
  });
  sort(b.begin(),b.end(),[](int l,int r){
    return l > r;
  });
  int res = 0;
  for(int i = 0; i < n;i++){
    res+=a[i]*b[i];
  }
  cout<<res;
}