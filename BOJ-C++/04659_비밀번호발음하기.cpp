/*
Date : 05/25/2020
version : gcc 9.2.0 c++17
problem : 
summary : string 
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
const string res[3] ={
  " is acceptable.\n",
  " is not acceptable.\n",
  " is not acceptable.\n"
};

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  string input;
  while(1){
    input.clear();
    cin>>input;
    if(input == "end")break;
    int sz = input.length();
    int flag = 0;
    int cntj = 0,cntm = 0;
    int cnt = 0;
    for(int i = 0; i < sz; i++){
      if(input[i] == 'a'){
        cnt++;
        if(cntm > 1){
          flag = 1;
          break;
        }cntm++;
        cntj = 0;
        if(i+1 != sz && input[i] == input[i+1]){
          flag = 1;
          break;
        }
      }else if(input[i] == 'e'){
        cnt++;
        if(cntm > 1){
          flag = 1;
          break;
        }cntm++;
        cntj = 0;
        
      }else if(input[i] == 'i'){
        cnt++;
        if(cntm > 1){
          flag = 1;
          break;
        }cntm++;
        cntj = 0;
        if(i+1 != sz && input[i] == input[i+1]){
          flag = 1;
          break;
        }
      }else if(input[i] == 'o'){
        cnt++;
        if(cntm > 1){
          flag = 1;
          break;
        }cntm++;
        cntj = 0;
      }else if(input[i] == 'u'){
        cnt++;
        if(cntm > 1){
          flag = 1;
          break;
        }cntm++;
        cntj = 0;
        if(i+1 != sz && input[i] == input[i+1]){
          flag = 1;
          break;
        }
      }else{
        if(cntj > 1){
          flag = 1;
          break;
        }cntj++;
        cntm = 0;
        if(i+1 != sz && input[i] == input[i+1]){
          flag = 1;
          break;
        }
      }
    }
    if(cnt == 0)flag = 1;
    cout<<"<"<<input<<">"<<res[flag];
  }
}