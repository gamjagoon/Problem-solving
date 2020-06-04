/*
Date : 06/03/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1992
summary : 분할 정복
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
char arr[65][65];
int N;

string solve(int s,int e){
  string ret = "";
  
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for (int i = 0 ; i < N; i++) {
    cin>>arr[i];
  }
  cout<<solve(1,N);
}
