/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : 롤케이크
summary : 시뮬레이션
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int L,N,p,k;
int max_cake = 0,real_max_cake = 0,max_cake_idx,real_max_cake_idx;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>L>>N;
	vector<bool>cake(L+1,false);
	int cal_cake = 0;
	int real_cake = 0;
	mfor(i,1,N){
		cin>>p>>k;
		real_cake = 0;
		cal_cake = k - p + 1;
		if(max_cake < cal_cake){
			max_cake_idx = i;
			max_cake = cal_cake;
		}
		mfor(i,p,k){
			if(!cake[i]){
				cake[i] = true;
				real_cake++;
			}
		}
		if(real_max_cake < real_cake){
			real_max_cake_idx = i;
			real_max_cake = real_cake;
		}
	}
	cout<<max_cake_idx<<endl;
	cout<<real_max_cake_idx;
}