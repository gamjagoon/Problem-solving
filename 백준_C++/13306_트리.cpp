/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/13306
summary : 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define fasio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

constexpr int Max = 200001;

int N,Q;

int parent[Max];
int id[Max],sz[Max];

int root(int ch){
	if(id[ch] != ch){
		return id[ch] = root(id[ch]);
	}
	return ch;
}

void munion(int l,int r){
	l = root(l);
	r = root(r);
	if(l == r)return;
	if(sz[l] >= sz[r]){
		id[r] = l;
		sz[l] += sz[r];
	}
	else{
		id[l] = r;
		sz[r] += sz[l];
	}
}

int main(){
	fasio
	cin>>N>>Q;
	mfor(i,1,N){
		id[i] = i;
	}
	int tmp;
	mfor(i,2,N){
		cin>>parent[i];
		munion(parent[i],i);
	}
	int a,b,c;
	Q += N-1;
	while(Q--){
		cin>>a>>b;
		if(a){
			cin>>c;
			b = root(b);
			c = root(c);
			if(b == c){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
		else{
			parent[b] = b;
			id[b] = b;
			c = root(b);
		}
	}
	return 0;
}


