
/*
Date : 07/04/2020
version : gcc 9.2.0 c++17
problem : 
summary : 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

//Global
string input;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>input;
  int N = input.length();
  for (int i = 0; i < N; i++)
  {
    cout<<i<<endl;
  }
}