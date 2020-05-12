/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : 
summary : 몫과 나머지
*/
#include <iostream>
#include <cmath>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global
int A,B;

int main() {
  io;
  cin>>A>>B;
  int Aa,Ba,Ab,Bb;
  Aa = A % 4;
  Ba = B % 4;
  Ab = A / 4;
  Bb = B / 4;
  if(Aa == 0)Ab--;
  if(Ba == 0)Bb--;
  cout<<abs(Ab-Bb) + abs(Aa-Ba);
}