/*
Date : 03/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11097
summary : 부분합 배열 + 스위핑
*/
#include <iostream>
#include <array>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

array <int,100002>A;
array <int,100002>swip{0};
array <ll,100002>sub{0};

int main(){
	io
	int n;
	cin>>n;
	mfor(i,1,n+1){
		cin>>A[i];
		sub[i] = sub[i-1] + A[i]; 
	}
	A[0] = -1;
	A[++n] = 0;
	ll res = 0,tmp;
	int r = 0,h = 0;
	mfor(i,1,n+1){
		while(A[swip[r]] >= A[i]){
			h = A[swip[r--]];
			tmp = h * (sub[i-1] - sub[swip[r]]);
			if(res < tmp)res = tmp;
		}
		swip[++r] = i;
	}
	cout<<res<<endl;
}