/*
Date : 05/27/2020
version : gcc 9.2.0 c++17
problem : 
summary : dfs
*/
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

//Global
vector<int> g[100001];
int able[100001];
bool ch[100001];
int arr[100001];
int N;
int s = 1;
bool E = false;

void dfs(int x) {
  if(E)return;
  s++;
  if(able[x]==0){
    return;
  }
  bool ret = false;
  int i,cur;
  int sz = g[x].size();
  for (i = 0; i < sz;) {
    cur = g[x][i];
    if (!ch[cur] && arr[s] == cur) {
      able[x]--;
      able[cur]--;
      ret = true;
      ch[x] = true;
      dfs(cur);
      i = 0;
      if(able[cur] == 0)break;
    }else{
      i++;
    }
  }
  if(!ret){
    E = true;
  };
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(int i = 0,a,b; i < N-1; i++){
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    able[a]++;
    able[b]++;
  }
  for(int i = 1; i <= N; i++){
    cin>>arr[i];
  }
  dfs(1);
  if(E)cout<<0;
  else cout<<1;
}