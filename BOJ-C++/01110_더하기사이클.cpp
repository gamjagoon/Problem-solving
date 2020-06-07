
/*
Date : 06/07/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1110
summary : 구현
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
void cycle(int &num){
  if(num < 10){
    num*10;
  }
  int tmp = num / 10 + num % 10;
  num = (num%10)*10 + tmp%10;
}

int N;
int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  int res = N;
  int cnt = 0;
  do{
    cnt++;
    cycle(N);
  }while(N != res);
  cout<<cnt;
}