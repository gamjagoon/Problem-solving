
/*
Date : 06/07/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/2745
summary : 진법
*/
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;

//Global
string input;
int B;
ll ctoll[255];
ll Pow[100];
ll com = 1000000000;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  ll num = 10;
  for(char i = 'A'; i <= 'Z';++i){
    ctoll[i] = num++;
  }
  cin>>input>>B;
  Pow[0] = 1;
  for(auto i = 1; i < 100; i++){
    Pow[i] = Pow[i-1]*B;
    if(Pow[i] > com)break;
  }

  ll result = 0;
  num = 0;
  for(auto s = input.end()-1; s != input.begin()-1;s--){
    if(*s >= '0' && *s <= '9'){
      result += Pow[num]*(ll)(*s-'0');
    }
    else{
      result += Pow[num]*ctoll[*s];
    }
    num++;
  }
  cout<<result;
}