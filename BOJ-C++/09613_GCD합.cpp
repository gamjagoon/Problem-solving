
/*
Date : 07/15/2020
version : gcc 9.2.0 c++17
problem : 
summary : implement
*/
#include <iostream>

#define endl '\n'
using namespace std;

//Global
int buf[101];

int gcd(int a,int b){
    int c=0;
    while(b!=0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solve(int c,int s,int e,long long cnt){
    if(s == e)return cnt;
    return solve(c,s+1,e,cnt+gcd(buf[c],buf[s]));
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    for(int i = 0;i < n;i++){
        cin>>buf[i];
    }
    long long res = 0;
    for(int i = 0; i< n;i++){
        res += solve(i,i+1,n,0);
    }
    cout<<res<<endl;
  }
}