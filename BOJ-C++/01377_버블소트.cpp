
/*
Date : 06/11/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1377
summary : 정렬
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
int N,cur,res = 0;
struct arr{
  int v,idx;
};
arr List[500001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(int i = 0; i < N; i++){
    cin>>cur;
    List[i] = {cur,i};
  }

  sort(List,List+N,[](arr &a, arr&b){
    if(a.v != b.v){
      return a.v < b.v;
    }
    return a.idx < b.idx;
  });
  int tmp;
  for(auto i = 0; i < N; i++){
    tmp = List[i].idx-i;
    if(tmp > res){
      res = tmp;
    }
  }
  cout<<res+1;
}