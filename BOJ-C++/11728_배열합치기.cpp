/*
Date : 05/02/2020
version : gcc 9.2.0 c++17
decribe : priority queue 
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);
#define DEBUG
using namespace std;

priority_queue<int,vector<int>,greater<int>>q;

int main() {
	io;
	int n,m;
	cin>>n>>m;
	int tmp;
	while(n--){
		cin>>tmp;
		q.push(tmp);
	}
	while(m--){
		cin>>tmp;
		q.push(tmp);
	}
	while(!q.empty()){
		cout<<q.top()<<' ';
		q.pop();
	}
}