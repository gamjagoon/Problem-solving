#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
constexpr int M = 1000000;
string input;int len;
int dp[5050];
int arr[5050];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>input;
	len = input.length();
	for(int i = 1; i<=len;i++){
		arr[i] = input[i-1]-'0';
	}
	if(len == 1 && input[0] == 0){
		cout<<0<<endl;
	}else{
		dp[0] = 1;
		for(int i = 1; i <= len;++i){
			if(arr[i] >= 1 && arr[i] <= 9){
				dp[i] = (dp[i-1] + dp[i])%M;
			}
			if(i == 1)continue;
			int tmp = arr[i] + arr[i-1]*10;
			if(10 <= tmp && tmp <= 26){
				dp[i] = (dp[i-2] + dp[i])%M;
			}
		}
		cout<<dp[len]<<endl;
	}
}
