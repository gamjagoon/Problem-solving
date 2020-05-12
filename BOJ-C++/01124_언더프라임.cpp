/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1124
summary : 수학
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
vector<int>plist;

//Global
bool NotPrime[100001];
void makeprime(int max){
  NotPrime[0] = NotPrime[1] = true;
  for(int i = 2; i <= max; i++){
    if(NotPrime[i])continue;
    plist.push_back(i);
    for(int j = i*2;j <= max;j+=i){
      NotPrime[j] = true;
    }
  }
}

bool NotUnderPrime(int N){
  int cnt = 0;
  for(auto i : plist){
    while(N % i == 0){
      N /= i;
      cnt++;
    }
    if(N == 1)break;
  }
  return NotPrime[cnt];
}

int main(){
  int A,B;
  cin>>A>>B;
  makeprime(B);
  int res = 0;
  Loop(i,A,B+1){
    if(!NotUnderPrime(i)){
      res++;
    }
  }
  cout<<res;
}

