#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global
bool P[10050];

void mark_prime(int M)
{
	for(int i = 4; i <= M; i+=2){
		P[i] = true;
	}
	for(int i = 3; i <= M; i++){
		if(P[i]) continue;
		for(int j = 2; j*i <= M; j++){
			P[j*i] = true;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	int m = 0 ;
	vector<int>input;
	while(t--){
		int tmp;cin>>tmp;
		input.push_back(tmp);
		m = tmp > m ? tmp : m;
	}
	mark_prime(m);
	for(auto i : input){
		for(int j = i / 2;  j > 0 ; j--){
			if(!P[j] && !P[i-j]){
				cout<<j<<' '<<i-j<<endl;
				break;
			}
		}
	}
}
