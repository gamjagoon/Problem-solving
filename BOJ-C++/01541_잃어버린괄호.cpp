#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global

string input;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>input;
	int len = input.length();
	int res = 0;
	int pval =0;
	for(int i = 0 ; i < len; i++){
		if(input[i] == '-'){
			int val = 0;
			int mval = 0;
			int j = i+1;
			for(; j < len; j++){
				if(input[j] == '+' || input[j] == '-'){
					mval+=val;
					val = 0;
					continue;
				}
				val *= 10;
				val += input[j] -'0';
			}
			mval += val;
			res -= mval;
			i = j;
		}else if(input[i] == '+'){
			res+= pval;
			pval = 0;
		}else{
			pval *= 10;
			pval += input[i]-'0';
		}
	}
	res += pval;
	cout<<res;
}

