/*
Date : 05/15/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/17470
summary : 구현
*/
#include <iostream>
#include <vector>
#include <array>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int R,C,R;
array< array<int,100>,100>arr;
array< array<int,100>,100>tmp;
vector<int>query;

void query_input(){
  int tmp,prev;
  Loop(i,0,R){
    cin>>tmp;
    if(query.empty())query.push_back(tmp);
    else{
      prev = query.back();
      if(tmp < 3){
        if(prev == tmp){
          continue;
        }
        query.push_back(tmp);
      }else if(tmp == 3){
        if(prev == 4){
          continue;
        }
        query.push_back(tmp);
      }else if(tmp == 4){
        if(prev == 3){
          continue;
        }
        query.push_back(tmp);
      }else if(tmp == 5){
        if(prev == 6){
          continue;
        }
        query.push_back(tmp);
      }else {
        if(prev == 5){
          continue;
        }
        query.push_back(tmp);
      }
    }
  }
}

void dup(array<array<int,100>,100>&a,array<array<int,100>,100>&b){
  for(int i = 0 ; i < R;i++){
    for(int j = 0; j < C; j++){
      a[i][j] = b[i][j];
    }
  }
}

void ver_rote(){
  for (int i = R, k = 1; i >= 1; i--, k++)
  {
    for (int j = 1; j <= C; j++)
    {
      tmp[k][j] = arr[i][j];
    }
  }
  dup(arr, tmp);
}

void hor_rote(){
  for (int i = 1, k = C; i <= C; i++, k--)
  {
    for (int j = 1; j <= R; j++)
    {
      tmp[k][j] = arr[i][j];
    }
  }
  dup(arr, tmp);
}

void right_rote(){
  for (int i = 1; i <= R; i++)
  {
    for (int k = 1, j = C; k <= C; k++, j--)
    {
      tmp[i][k] = arr[j][i];
    }
  }
  swap(R,C);
  dup(arr, tmp);
}

void left_rote(){
  for (int i = C, r = 1; i >= 1; i--, r++)
  {
    for (int k = 1, j = 1; k <= R; k++, j++)
    {
      tmp[r][k] = arr[j][i];
    }
  }
  swap(R,C);
  dup(arr, tmp);
}