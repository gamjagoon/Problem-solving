#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

string input,A[101];
int input_len,A_len[101],dp[101],N;

int solve() {
	dp[input_len] = 1;
	for(int cur = input_len - 1; cur >= 0; cur--){
		for(int j = 0; j < N; ++j){
			if(input.find(A[j], cur) == cur && dp[cur+A[j].length()] == 1){
				dp[cur] = 1;
				break;
			}else {
				dp[cur] = 0;
			}
		}
	}
	return dp[0];	
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>input>>N;
	input_len = input.size();
	for(int i = 0;i < N;i++){
		cin>>A[i];
		A_len[i] = A[i].size();
	}
	cout<<solve();
}















