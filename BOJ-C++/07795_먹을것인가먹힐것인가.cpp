
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : 구현
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
int A[20000];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int t;cin>>t;
  while(t--){
    int a,b;cin>>a>>b;
    for (int i = 0; i < a; i++)
    {
      cin>>A[i];
    }
    sort(A,A+a);
    int tmp,cnt = 0;
    for (int i = 0; i < b; i++)
    {
      cin>>tmp;
      for(int j = a-1; A[j] > tmp; j--){
        cnt++;
      }
    }
    cout<<cnt<<endl;
  }
}