/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1976
summary : 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define fasio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

constexpr int Max = 1000001;

int N,M;

int id[Max],sz[Max];

int root(int ch){
	if(id[ch] != ch){
		return id[ch] = root(id[ch]);
	}
	return ch;
}

void munion(int a,int b){
	a = root(a);
	b = root(b);
	if(a == b)return;
	if(sz[a] > sz[b]){
		id[b] = a;
		sz[a] += sz[b];
	}
	else{
		id[a] = b;
		sz[b] += sz[a];
	}
}

int main(){
	fasio
	cin>>N>>M;
	mfor(i,1,N){
		id[i] = i;
		sz[i] = 1;
	}
	int a,b,c;
	while(M--){
		cin>>a>>b>>c;
		if(a){
			b = root(b);
			c = root(c);
			if(b == c){
				cout<<"yes\n";
			}
			else{
				cout<<"no\n";
			}
		}
		else{
			munion(b,c);
		}
	}
}
