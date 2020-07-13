
/*
Date : 07/13/2020
version : gcc 9.2.0 c++17
problem : 
summary : 수학
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  ld A,B,C;
  long long res = 0;
  cin>>A>>B>>C;
  ld a = A*B/C;
  ld b = A/B*C;
  a = a > b ? a : b;
  res = (long long)a;
  cout<<res;
}