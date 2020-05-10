/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : 
summary : 
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int resmax = INT32_MIN;
int resmin = INT32_MAX;
int num[11];
//0 + 1 - 2 x 4 /
int D[4];
int N;

inline int mmax(int a,int b){
	return a > b ? a : b;
}
inline int mmin(int a,int b){
	return a > b ? b : a;
}
void update(int num){
	resmax = mmax(resmax,num);
	resmin = mmin(resmin,num);
}

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0; i < N;++i){
		cin>>num[i];
	}
	for(int i = 0 ; i < 4; ++i){
		cin>>D[i];
	}
}

void dfs(int idx,int val){
	if(idx >= N){
		update(val);
		return;
	}
	for(int i = 0 ; i <= 3; ++i){
		if(D[i] > 0){
			D[i]--;
			switch (i)
			{
			case 0:
				dfs(idx+1,val+num[idx]);
				break;
			case 1:
				dfs(idx+1,val-num[idx]);
				break;
			case 2:
				if(val == 0)dfs(idx+1,0);
				else dfs(idx+1,val*num[idx]);
				break;
			default:
				if(val == 0)dfs(idx+1,0);
				else dfs(idx+1,val/num[idx]);
				break;
			}
			D[i]++;
		}
	}
}
int main(){
	Input();
	dfs(1,num[0]);
	cout<<resmax<<endl<<resmin;
	return 0;
}