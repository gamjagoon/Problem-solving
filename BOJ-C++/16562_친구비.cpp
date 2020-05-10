/*
Date : 02/24/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/16562
summary : 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define fasio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

constexpr int Max = 100001;

int G,P;

int id[Max];
bool ch[Max];

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
	id[a] = b;
}

int main(){
	fasio
	cin>>G>>P;
	mfor(i,1,G){
		id[i] = i;
	}
	int tmp;
	int blank;
	int cnt = 0;
	while(P--){
		cin>>tmp;
		blank = root(tmp);
		if(blank == 0){
			break;
		}
		else{
			cnt++;
			munion(blank, blank - 1);
		}
	}
	cout<<cnt<<endl;
	return 0;
}
