/*
Date : 05/14/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/10836
summary : 시뮬 구현
*/
#include <iostream>
#define endl '\n'
using namespace std;
int M,N;
int arr[1500];


//Global
int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>M>>N;
  int len = M*2 -1;
  int a,b,c;
  while(N--){
    cin>>a>>b>>c;
    arr[a]++;
    arr[a+b]++;
  }
  for(int i = 1; i < len;i++){
    arr[i]+=arr[i-1];
    arr[i-1]++;
  }
  arr[len-1]++;
  for(int r = 0; r < M; r++){
    cout<<arr[len - M - r]<<' ';
    for(int c =M ; c < len; c++){
        cout<<arr[c]<<' ';
    }
    cout<<endl;
  }
}