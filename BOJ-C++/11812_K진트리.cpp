
/*
Date : 06/11/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/11812
summary : LCA ,DFS
*/
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

//Global
typedef long long ll;
ll N, K, Q,a,b,tmp;
ll level[100];

ll parent(ll arg){
  return (arg+K - 2) / K;
}

ll get_level(ll now){
  ll i = 0;
  while(now > level[i]){
    i++;
  }
  return i;
}

void init() {
  level[0] = 1;
  size_t i= 1;
  ll cur = 1;
  ll prev = 1;
  while (cur < N)
  {
    prev+=cur*K;
    level[i] = prev;
    cur*=K;
    i++;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>N>>K>>Q;
  if(K != 1){
    init();
  }
  while(Q--)
  {
    cin>>a>>b;
    if (K == 1)
		{
			if(a >= b)cout<<a - b<<endl;
			else cout<<b - a<<endl;
			continue;
		}
    ll lev_A{get_level(a)},lev_B{get_level(b)};
    tmp = 0;
    while(lev_A < lev_B){
      b = parent(b);
      lev_B = get_level(b);
      tmp++;
    }
    while(lev_A > lev_B){
      a = parent(a);
      lev_A = get_level(a);
      tmp++;
    }
    while(a != b){
      a = parent(a);
      b = parent(b);
      tmp+=2;
    }
    cout<<tmp<<endl;
  }
}