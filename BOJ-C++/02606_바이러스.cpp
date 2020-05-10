/*
Date : 02/09/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2606
summary : 
*/
#include <iostream>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int id[101] = {0,1,};
int N;

int root(int ch){
	if(id[ch] != ch){
		return id[id[ch]]  = root(id[ch]);
	}
	return ch;
}

void make_union(int p,int q){
	p = root(p);
	q = root(q);
	if(p == q)return;
	if(p > q){
		id[p] = q;
	}
	else{
		id[q] = p;
	}
}

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	mfor(i,0,N){
		id[i] = i;
	}
	int M;
	cin>>M;
	int a,b;
	while(M--){
		cin>>a>>b;
		make_union(a,b);
	}
}

int Solve(){
	int ret = 0;
	mfor(i,2,N){
		if(root(i) == 1){
			ret++;
		}
	}
	return ret;
}

int main(){
	Input();
	cout<<Solve()<<endl;
	return 0;
}