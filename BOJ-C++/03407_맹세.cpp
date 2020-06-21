
/*
Date : 06/21/2020
version : gcc 9.2.0 c++17
problem : 
summary : 백 트래킹
*/
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;

//Global
string List[] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac",
                  "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os",
                  "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm",
                  "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es",
                  "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no",
                  "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };

set<string>mset;
string input;
int L;
bool ch[50000];

void solve(int start) {
  bool ret = false;
  queue<int> q;
  q.push(start);
  ch[start] = true;

  string tmp1,tmp2;
  while(!q.empty())
  {
    int cur = q.front();q.pop();
    if(cur == L)
    {
      ret = true;
      break;
    }

    tmp1.clear();
    tmp2.clear();
    tmp1 = input[cur];
    tmp2 = input.substr(cur,2);

    if(mset.count(tmp1) == 1 && ch[cur + 1]== false){
      ch[cur+1] = true;
      q.push(cur+1);
    }
    if(mset.count(tmp2) == 1&& ch[cur+2] == false){
      ch[cur+2] = true;
      q.push(cur+2);
    }
  }
  if(ret)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  for(auto i : List){
    mset.insert(i);
  }
  int T;cin>>T;
  while(T--){
    input.clear();
    cin>>input;
    L = input.length();
    memset(ch,false,sizeof(ch));
    solve(0);
  }
}