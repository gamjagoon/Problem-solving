
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
int point[80001];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int d = 200;
  for(int i = 1; i <= 10;i++){
    int e = d - 20;
    e *= e;
    for(int j = d*d; j >e;j--){
      point[j] = i;
    }
    d -= 20;
  }
  point[0] = 10;
  int tc;cin>>tc;
  while (tc--)
  {
    int N;cin>>N;
    int x,y;
    int res =0;
    for(int i = 0; i < N;i++){
      cin>>x>>y;
      int tmp = x *x + y*y;
      res += point[tmp];
    }
    cout<<res<<endl;
  }
  
}