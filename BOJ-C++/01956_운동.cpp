/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1956
summary : 플로이드  와샬샬
*/
#include <iostream>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
#define INF 1000000009
using namespace std;

//Global
int arr[401][401];
int V,E;

int main() 
{
  io;
  cin>>V>>E;
  Loop(r,1,V+1){
    Loop(c,1,V+1){
      arr[r][c] = INF;
    }
  }
  Loop(r,1,V+1){
    arr[r][r] = 0;
  }
  int from,to,dis;
  Loop(i,0,E){
    cin>>from>>to>>dis;
    arr[from][to]=dis;
  }
  Loop(k,1,V+1){
    Loop(i,1,V+1){
      Loop(j,1,V+1){
        if(arr[i][j] > arr[i][k] + arr[k][j]){
          arr[i][j] = arr[i][k] + arr[k][j];
        }
      }
    }
  }
  int result = INF;
  Loop(i,1,V+1){
    Loop(j,1,V+1){
      if(i == j){
        continue;
      }
      if(arr[i][j] +arr[j][i] < result){
        result = arr[i][j] + arr[j][i];
      }
    }
  }
  if(result == INF)cout<<-1;
  else {
  cout<<result;
  }
}