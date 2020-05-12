/*
Date : 05/12/2020
version : gcc 9.2.0 c++17
problem : 
summary : 구현
*/
#include <iostream>
#include <string>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

//Global

pair<string,string> solve(){
  string name;cin>>name;
  string eli;
  string S1,S2;
  int S;
  cin>>S1>>S2>>S;
  int y1 = stoi(S1.substr(0,4),nullptr,0);
  int y2 = stoi(S2.substr(0,4),nullptr,0);
  if(2009 < y1)eli = "eligible";
  else if (1990 < y2)eli = "eligible";
  else{
    int m = S / 5;
    if(8 < m)eli = "ineligible";
    else if(8 == m && S % 5)eli = "ineligible";
    else {
      eli = "coach petitions";
    }
  }
  return {name,eli};
}

int main() {
  io;
  int tc;cin>>tc;
  while(tc--){
    auto[name,eli] = solve();
    cout<<name<<' '<<eli<<endl;
  }
}