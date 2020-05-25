/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : 
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll M = 1000000001;
//Global
ll N,Q;
ll a,b;
ll arr[1000001];
int res = 0;

void solve(){
  res = upper_bound(arr,arr+N,b) -lower_bound(arr,arr+N,a);
} 

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>Q;
  arr[N] = M;
  for(size_t i = 0,tmp; i < N; i++){
    cin>>arr[i];
  }
  sort(arr,arr+N);
  for(size_t i = 0; i < Q; i++){
    cin>>a>>b;
    solve();
    cout<<res<<endl;
  }
  
}