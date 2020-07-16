
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : implement
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

//Global
struct P
{
  int N,n,p;
};
int arr[101];
vector<P> list;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  list.resize(N);for(auto &i : list){
    cin>>i.N>>i.n>>i.p;
  }
  sort(list.begin(),list.end(),[](P&l, P&r){
    return l.p > r.p;
  });
  int cnt = 0;
  for(auto i : list){
    if(cnt == 3)break;
    if(arr[i.N] == 2)continue;
    cout<<i.N<<' '<<i.n<<endl;
    arr[i.N]++;
    cnt++;
  }
}