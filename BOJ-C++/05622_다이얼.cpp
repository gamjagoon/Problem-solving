
/*
Date : 06/01/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/5622
summary : 구현
*/
#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

//Global
int dial[255];
char input[20];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int j = 3;
  for(int c = 'A',cnt = 0; c <= 'O';c++){
    dial[c] = j;cnt++;
    if(cnt % 3 == 0)j++;
  } 
  dial['P'] = 8;
  dial['Q'] = 8;
  dial['R'] = 8;
  dial['S'] = 8;
  dial['T'] = 9;
  dial['U'] = 9;
  dial['V'] = 9;
  dial['W'] = 10;
  dial['X'] = 10;
  dial['Y'] = 10;
  dial['Z'] = 10;
  cin>>input;
  int res = 0;
  for(auto i : input){
    if(i != '\0'){
      res += dial[i];
    }else{
      break;
    }
  }
  cout<<res;
}