#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
int P[246913];
bool ch[426913];
int num = 2;

void init(int m){
	for(; num <=m;num++){
		P[num] = P[num-1];
		if(!ch[num]){
			P[num]++;
			for(int j = num;j <=m;j+=num){
				ch[j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N;
	vector<int>input;
	int M = 0;
	while(1){
		cin>>N;if(N == 0)break;
		int m = 2*N;
		M = M > m ? M : m;
		input.push_back(N);
	}
	init(M);
	for(auto i : input){
		int m = 2*i;
		cout<<P[m] - P[i]<<endl;
	}
}
















