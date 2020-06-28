
/*
Date : 06/28/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/3035
summary : 구현 
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
int r,c,zr,zc;
char arr[51][51];
int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>r>>c>>zr>>zc;
  for(int i = 0; i < r; i++){
    cin>>arr[i];
  }
  for(int i = 0; i < r;i++){
    for(int a = 0; a < zr; a++){
      for(int j = 0; j < c; j++){
        for(int b = 0; b < zc; b++){
          cout<<arr[i][j];
        }
      }cout<<endl;
    }
  }
}