/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/2531
summary : cnt
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
int N,d,k,c;
int arr[60002];
int ch[3001];
int cur;

void init() {
  cur++;
  ch[c]++;
  for(int i = 1,now; i < k;i++){
    now = arr[i];
    if(ch[now] == 0)cur++;
    ch[now]++;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>d>>k>>c;
  for(int i = 1; i <= N; i++){
    cin>>arr[i];
  }
  for(int i = 1; i < k;i++){
    arr[i+N] =arr[i];
  }
  init();
  int res = 0;
  for(int i = 1,now,prev; i <= N;i++){
    now = arr[i+k-1];
    prev = arr[i];
    if(ch[now] == 0)cur++;
    ch[now]++;
    res = res > cur ? res : cur;
    ch[prev]--;
    if(ch[prev]==0)cur--;
  }
  cout<<res;
}