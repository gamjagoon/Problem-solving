
/*
Date : 07/04/2020
version : gcc 9.2.0 c++17
problem : 
summary : 
*/
#include <iostream>
#include <cstring>

#define endl '\n'
using namespace std;

//Global

int arr[10001];
pair<int,int> dp[10001][10001];

int cnt,j;
int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  int n,k,m;
  while (1)
  {
    cin>>n>>k>>m;
    if(n == 0)break;
    if(dp[n][k].first != 0){
      cnt = dp[n][k].second;
      j =( dp[n][k].first - cnt + m)% n;
      if(j == 0)cout<<n<<endl;
      else cout<< j<<endl;
      continue;
    }
    memset(arr,0,sizeof(arr));
    cnt = 0;
    int N = n;
    j = m;
    cnt = k-1;
    while(1){
      if(arr[j] == 0 )cnt++;
      if(cnt == k){
        --N;
        arr[j] = -1;
        cnt = 0;
        if(N <= 0)break;
      }
      j++;
      if(j > n)j = 1;
    }
    dp[n][k].first = j;
    dp[n][k].second = m;
    cout<<j<<endl;
  }
  
}