#include <iostream> 
#include <algorithm>
using namespace std; 

int arr[5000], dp[5000];

int main () {
  ios::sync_with_stdio(false);cin.tie(0);
  int N;
  cin>>N;
  if(N == 1){
    cout<<0;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    cin>>arr[i];
    dp[i] = 1;
  }
  sort(arr,arr+N);
  int mx_dp = 1;
  for (int i = 1; i < N; i++) {
    for(int j = 0; j < i; j++){
      if(arr[i] % arr[j] == 0){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    mx_dp = mx_dp > dp[i] ? mx_dp : dp[i];
  }
  cout<<N - mx_dp;
  return 0;
}