/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : counting
*/
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

//Global
int res[101][13];
int N,M;
string day,month,year;
string arr[13]={
"",
"Jan:",
"Feb:",
"Mar:",
"Apr:",
"May:",
"Jun:",
"Jul:",
"Aug:",
"Sep:",
"Oct:",
"Nov:",
"Dec:"
};

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int T = 1;
  while(1){
    cin>>N;
    if(N == 0)break;
    for(int i = 0; i < N; i++){
      cin>>day>>month>>year;
      M = stoi(month,0,10);
      res[T][M]++;
    }
    T++;
  }
  for(int i = 1; i < T; i++){
    cout<<"Case #"<<i<<":\n";
    for(int j = 1; j <= 12; j++){
      cout<<arr[j];
      for(int k = 0; k < res[i][j]; k++){
        cout<<"*";
      }cout<<endl;
    }
  }
}