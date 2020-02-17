/*
Date : 02/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/14501
summary : dfs
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;


int N,time[16],point[16];
int res = 0;


void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	int a,b;
	mfor(i,1,N){
		cin>>a>>b;
		time[i] = a;
		point[i] = b;
	}
}


void dfs(int now,int val){
	if(now == N+1){
		res = res < val ? val : res;
		return;
	}
	int nex = now + time[now];
	for(int i = nex; i <= N + 2; ++i){
		if(i <= N + 1){
			dfs(i,val+point[now]);
		}
		else{
			res = res < val ? val : res;
			break;
		}
	}
}


int main(){
	Input();
	for(int i = 1; i <= N; ++i){
		dfs(i,0);
	}
	cout<<res;
	return 0;
}