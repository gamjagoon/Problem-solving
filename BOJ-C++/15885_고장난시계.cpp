/*
Date : 10/01/2020
version : gcc 9.2.0 c++17
problem : 
summary : math
*/
#include <iostream>
#include <math.h>
#define endl '\n'
using namespace std;

//Global
long double A,B,res;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>A>>B;
  res = 2*abs(A/B - 1);
  cout<<(int)res;
}