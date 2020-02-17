/*
Date : 02/09/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1068
summary : 그래프탐색
*/
#include <iostream>
#include <queue>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

deque<int>child[51];
int parent[51],N,root;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	int tmp;
	mfor(i,0,N-1){
		cin>>tmp;
		parent[i] = tmp;
		if(tmp == -1){
			root = i;
			continue;
		}
		child[tmp].push_back(i);
	}
}

int sum_child(int n){
	if(child[n].empty()){
		return 1;
	}
	int ret = 0;
	for(int i = 0 ; i < child[n].size();++i){
		ret += sum_child(child[n][i]);
	}
	return ret;
}

int main(){
	Input();	
	int res = 0;
	int tmp;
	cin>>tmp;
	if(parent[tmp] == -1){
		res = 0;
	}
	else {
		child[tmp].clear();
		int p = parent[tmp];
		int poped;
		while(1){
			poped = child[p].front();
			child[p].pop_front();
			if(poped == tmp){
				break;
			}
			child[p].push_back(poped);
		}
		res = sum_child(root);
	}
	cout<<res;
	return 0;
}