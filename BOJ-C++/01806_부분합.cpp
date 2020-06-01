/*
Date : 05/30/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1806
summary : two pointer
*/
#include <iostream>

#define endl '\n'
#define INF 1000000009
using namespace std;

//Global
int N,S;
int arr[100001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>S;
  int s = 0; int e = 0;
  int res = INF;
  for(auto i = 0; i < N; i++){
    cin>>arr[i];
  }
  int Sum = arr[0];
  while (1)
  {
    if(s > e || N <= e){
      break;
    }
    else{
      if(Sum >= S){
        int mid = e - s +1;
        if(mid < res){
          res = mid;
        }
        Sum-=arr[s++];
      }else{
        e++;
        Sum+=arr[e];
      }
    }
  }
  if(res == INF)cout<<0;
  else cout<<res;
}