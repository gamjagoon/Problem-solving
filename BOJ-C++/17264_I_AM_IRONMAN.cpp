/*
Date : 05/06/2020
version : gcc 9.2.0 c++17
problem : 
summary : 문자열 매칭
*/
#include <iostream>
#include <unordered_map>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);
//#define DEBUG
using namespace std;

//Global
unordered_map<string,bool>P;
int N,pnum;
int W,L,O;

int main() {
  io
  cin>>N>>pnum;
  int score = 0;
  cin>>W>>L>>O;
  Loop(i,0,pnum){
    string arg1,arg2;
    cin>>arg1>>arg2;
    #ifdef DEBUG
    cout<<"input = "<<arg1<<' '<<arg2<<endl;
    #endif
    if(arg2 == "W"){
      P[arg1] = true;
    }else {
      P[arg1] = false;
    }
  }
  while(N--){
    string tmp;
    cin>>tmp;
    bool res = P[tmp];
    if(res){
      score += W;
    }else{
      score -= L;
      if(score < 0)score = 0;
    }
    #ifdef DEBUG
    cout<<"input = "<<tmp<<" res = "<<res<<"score = "<<score<<endl;
    #endif
    if(score >= O){
      cout<<"I AM NOT IRONMAN!!";
      return 0;
    }
  }
  cout<<"I AM IRONMAN!!";
}