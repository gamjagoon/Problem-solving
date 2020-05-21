/*
Date : 05/21/2020
version : gcc 9.2.0 c++17
problem : 
summary : Dp
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
int R,C;
//Global
int arr[1001][1001];
int res = 0;

int main(){
  io;
  cin>>R>>C;
  Loop(i,0,R){
    string tmp;
    cin>>tmp;
    Loop(j,0,C){
      arr[i][j] = tmp[j]-'0';
    }
  }
  if(R < 2 || C < 2){
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C;j++){
        if(arr[i][j] == 1){
          res=1;
        }
      }
    }
  }else{
    for(int i = 1; i < R;i++){
      for(int j = 1; j < C;j++){
        if(arr[i][j] == 1){
          int val = min({arr[i-1][j],arr[i-1][j-1],arr[i][j-1]})+1;
          arr[i][j] = val;
          res = max(arr[i][j],res);
        }
      }
    }
  }
  cout<<res*res;
}