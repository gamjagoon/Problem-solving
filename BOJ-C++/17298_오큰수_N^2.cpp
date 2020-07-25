
/*
Date : 07/18/2020
version : gcc 9.2.0 c++17
problem : 
summary : 쿼리
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

//Global
int input[1000000];
int res[1000000];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;cin>>N;
  for(int i = 0; i < N;i++){
    cin>>input[i];res[i] = -1;
    for(int j = 0; j < i;j++){
      if(res[j] == -1 && input[j] < input[i]){
        res[j] = input[i];
      }
    }
  }
  for(int i = 0; i < N;i++){
    cout<<res[i]<<' ';
  }
}