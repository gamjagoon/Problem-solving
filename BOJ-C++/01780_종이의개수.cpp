/*
Date : 05/21/2020
version : gcc 9.2.0 c++17
problem : 
summary : 분할정복
*/
#include <iostream>

#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

constexpr int SZ = 2190;
//Global
int N;
int plist[9];
int arr[SZ][SZ];
bool ch[SZ][SZ];
int cnt[3];

bool search(int r,int c,int n,int com){
  int R = r+plist[n];int C = c+plist[n];
  if(R > N || C > N)return false;
  for(int i = r; i < R;i++){
    for(int j = c;j < C; j++){
      if(ch[i][j])return false;
      if(arr[i][j] != com)return false;
    }
  }
  cnt[com+1]+=1;
  for(int i = r; i < R;i++){
    for(int j = c;j < C; j++){
      ch[i][j] = true;
    }
  }
  return true;
}

int main(){
  io;
  plist[0] = 1;
  for(int i = 0; i < 8;i++){
    plist[i+1] = plist[i]*3;
  }
  int k = 1;
  cin>>N;
  while(plist[k]!=N){
    k++;
  }
  for(int i = 0; i < N;i++){
    for(int j = 0 ;j < N;j++){
      cin>>arr[i][j];
    }
  }
  for(;k >= 0;k--){
    for(int i =0;i < N; i+=plist[k]){
      for(int j = 0;j < N;j+=plist[k]){
        if(ch[i][j])continue;
        for(int com = -1;com <2;com++){
          if(!search(i,j,k,com)){
            continue;
          }else{
            break;
          }
        }
      }
    }
  }
  for(int i = 0; i < 3;i++){
    cout<<cnt[i]<<endl;
  }
}