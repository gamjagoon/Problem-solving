
/*
Date : 06/01/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1181
summary : 정렬
*/
#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
using namespace std;

//Global
string input[20000];
set<string>ch;
int N;
int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  string tmp;
  int j = 0;
  for(int i = 0; i < N;i++){
    cin>>tmp;
    if(ch.count(tmp) == 1)continue;
    input[j++] = tmp;
    ch.insert(tmp);
  }
  sort(input,input+j,[](string &A,string &B){
    auto a{A.length()};
    auto b{B.length()};
    if(a== b){
      return A < B;
    }else{
      return a < b;
    }
  });
  for(size_t k = 0; k < j; k++){
    cout<<input[k]<<endl;
  }
}