/*
Date : 05/30/2020
version : gcc 9.2.0 c++17
problem : 
summary : 위상정렬
*/
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

//Global
int N;
string IntTochar="";
char CharToInt[255];
string arr[100];
int indegree[26];
bool g[26][26];
bool use[26];
int gsize[26];
string result = "";
queue<int>q;
int L = 0;

int main() {
  for(char a = 'a';a <= 'z';a++){
    IntTochar.push_back(a);
  }
  for(size_t i = 0,sz = IntTochar.size();i < sz;i++){
    CharToInt[IntTochar[i]] = i;
  }
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(auto i = 0; i < N; i++){
    cin>>arr[i];
    for(auto j : arr[i]){
      use[CharToInt[j]] = true;
    }
  }
  int pre,cur,sz;
  for(auto r = 1; r < N; r++){
    pre = arr[r-1].length();
    cur = arr[r].length();
    sz = pre < cur ? pre : cur;
    bool diff = false;
    for(auto c = 0; c < sz;c++){
      int a{CharToInt[arr[r-1][c]]};
      int b{CharToInt[arr[r][c]]};
      if(a != b){
        diff = true;
        if(!g[a][b]){
          indegree[b]++;
          g[a][b] = 1;
          gsize[a]++;
        }
        break;
      }
    }
    if(!diff && pre > cur){
      cout<<"!\n";
      return 0;
    }
  }
  bool wrong = false;
  int wrongcnt = 0;
  for(int i = 0 ; i < 26;i++){
    if(!use[i])continue;
    // cout<<IntTochar[i]<<' '<<indegree[i]<<'|';
    // for(int j = 0; j < 26; j++){
    //   if(g[i][j])cout<<IntTochar[j]<<' ';
    // }cout<<endl;
    L++;
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  bool mul = false;
  for(int i = 0 ; i < L;i++){
    if(q.empty()){
      cout<<"!\n";
      return 0;
    }
    if(q.size() >= 2){
      mul = true;
    }
    cur = q.front();q.pop();
    use[cur] = false;
    result.push_back(IntTochar[cur]);
    for(auto j = 0; j < 26; j++){
      if(g[cur][j]){
        if(--indegree[j] == 0){
          if(use[j] == false){
            cout<<"!\n";
            return 0;
          }
          q.push(j);
        }
      }
    }
  }
  if(mul){
    cout<<"?\n";
  }else{
    cout<<result<<endl;
  }
}