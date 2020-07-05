
/*
Date : 07/04/2020
version : gcc 9.2.0 c++17
problem : 
summary : 
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
string A,B;

int main() {
  char a;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>A>>a>>B;
  if(a == '*'){
    int res = 0;
    res+= A.length() + B.length();
    res -= 2;
    cout<<'1';
    for (size_t i = 0; i < res; i++)
    {
      cout<<'0';
    }
  } else {
    if(A.length() < B.length()){
      swap(A,B);
    }
    if(A.length() == B.length()){
      A[0] = '2';
      cout<<A;
    }else if(B[0] == '0'){
      cout<<A;
    } 
    else {
      int cnt =A.length()-B.length();
      A[cnt] = '1';
      cout<<A;
    }
  }
}