/*
Date : 02/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1182
summary : 비트셋 이용 풀이
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int N,S,F,res = 0;
int arr[20];

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>S;
	mfor(i,0,N-1){
		cin>>arr[i];
	}
}

void Solve(int idx,int val){
	val += arr[idx];
	if(idx >= N)return;
	if(val == S)res++;
	Solve(idx+1,val-arr[idx]);
	Solve(idx+1,val);
}

int main(){
	Input();
	Solve(0,0);
	cout<<res<<endl;
	return 0;
}