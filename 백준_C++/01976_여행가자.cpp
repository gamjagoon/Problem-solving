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

constexpr int Max = 201;

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
	mfor(i,1,N){
		int tmp;
		mfor(j,1,N){
			cin>>tmp;
			if(j < i)continue;
			if(tmp){
				munion(i,j);
			}
		}
	}
	int prev,now;
	cin>>now;
	prev = now = root(now);
	M--;
	bool j = true;
	while(M--){
		cin>>now;
		now = root(now);
		if(prev != now){
			cout<<"NO\n";
			j = false;
			break;
		}
		prev = now;
	}
	if(j){
		cout<<"YES\n";
	}
}
