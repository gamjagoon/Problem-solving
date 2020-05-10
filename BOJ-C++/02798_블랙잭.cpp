/*
Date : 05/02/2020
version : gcc 9.2.0 c++17
decribe : selection 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);
//#define DEBUG
using namespace std;

int N,M;
vector<int>input;

int call_res(int a,int b,int c){
	return input[a]+input[b]+input[c];
}

int main() {
	io;
	cin>>N>>M;
	input.resize(N);
	for(auto &i:input){
		cin>>i;
	}
	sort(input.begin(),input.end());
	int s = 0;
	while(s < N){
		if(input[s] > M)break;
		s++;
	}
	N = s;
	int result = 0;
	int diff = INF;
	Loop(i,0,N){
		Loop(j,i+1,N){
			Loop(k,j+1,N){
				int res = call_res(i,j,k);
				#ifdef DEBUG
				std::cout<<i<<" "<<j<<' '<<k<<"res "<<res<<'\n';
				#endif
				if(res > M)continue;
				int dif = M - res;
				if(diff > dif){
					diff =  dif;
					result = res;
					#ifdef DEBUG
					std::cout<<"result : "<<result<<"\n";
					#endif
				}
			}
		}
	}
	cout<<result<<endl;
}