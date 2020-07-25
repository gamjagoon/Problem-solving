
/*
Date : 07/18/2020
version : gcc 9.2.0 c++17
problem : 
summary : 스
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
char res[1000001];
string A,B;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>A>>B;
  int len_A=A.length(),len_B =B.length();
  int idx = 0,a = 0,b = 0;
  for(int a = 0; a < len_A;a++)
  {
    res[idx] = A[a];
    if(res[idx] == B[b]){
      if(b == len_B-1){ // 마지막인경우
        idx -= len_B;
        b = 0;

        int len  = idx - len_B + 1;
        for(int i = 0; i < len_B;i++){
          if(res[len+i] == B[b]){
            b++;
          } else{
            b = 0;
          }
        }
      } else{
        b++;
      }
    } else{
      b = 0;
      if(res[idx] == B[0]){
        b++;
      }
    }
    idx++;
  }
  if(idx <= 0){
    cout<<"FRULA";
  }else{
    for(int i = 0; i < idx;i++){
      cout<<res[i];
    }
  }
  
}