
/*
Date : 07/13/2020
version : gcc 9.2.0 c++17
problem : 
summary : 구현
*/
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

//Global
int N;
int n1,n2;
bool flag = false;
int cursor = 1;
string arr[100];

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N;
  for(int i = 0 ; i < N;i++){
    cin>>arr[i];
    if(!flag && arr[i] == "KBS1"){
      n1 = i;
    }else if(!flag && arr[i] == "KBS2"){
      n2 = i;
      flag = true;
    }
  }

  //1 n1을 제일위로 올린다.
  //2 n2을 제일위로 올린다.
  int tmp,cnt = 0;
  int sz = 0;
  vector<char> instructions;
  if(n1 < n2){// n1 이 n2 보다 적은경우
    tmp = n1 - cursor;
    cursor = tmp;
    cnt += tmp;
    while(tmp--){
      instructions.push_back('1');
    }
    tmp = cursor;
    cnt += tmp;
    while(tmp--){
      instructions.push_back('4');
    }
    cursor = 1;
    tmp = n2 - cursor;
    cnt += tmp;
    while(tmp--){
      instructions.push_back('1');
    }
  }else {
    
  }
}