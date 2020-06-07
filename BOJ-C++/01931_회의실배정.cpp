
/*
Date : 06/07/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/1931
summary : Greedy
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

//Global
int N;
struct Time{
	int s,e;
};
Time table[100001];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N;
	for(auto i = 0; i < N; i++){
		cin>>table[i].s>>table[i].e;
	}
	sort(table,table+N,[](Time& A,Time& B){
		if(A.e == B.e){
			return A.s < B.s;
		}
		return A.e < B.e;
	});
	int cur = 0,res = 0;
	for(auto i = 0; i < N; i++){
		if(cur <= table[i].s){
			cur = table[i].e;
			res++;
		}
	}
	cout<<res;
}