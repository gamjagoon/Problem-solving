
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : 구현
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
pair<int,int> arr[50];
int cnt[50];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  for (size_t i = 0; i < N; i++)
  {
    cin>>arr[i].first >>arr[i].second;
    cnt[i] = 1;
  }
  for(int i = 0; i < N;i++){
    for(int j = 0; j < N;j++){
      if(i == j)continue;
      if(arr[i].first > arr[j].first && arr[i].second > arr[j].second){
        cnt[j] += 1;
      }
    }
  }
  for (size_t i = 0; i < N; i++)
  {
    cout<<cnt[i]<<' ';
  }
  
}