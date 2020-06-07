
/*
Date : 06/07/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/15663
summary : 백트래킹
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#define endl '\n'
using namespace std;

//Global

int N,M;
int input[8];
bool ch[8];
int instruct[8];
unordered_set<string>ms;

string tmp;
void dfs(int sz){
	if(sz == M){
		tmp.clear();
		for(auto i = 0; i < M; i++){
			tmp+=to_string(input[instruct[i]]);
			tmp+=" ";
		}
		tmp.back() = '\n';
		if(ms.count(tmp)){
			return;
		}else{
			ms.insert(tmp);
			cout<<tmp;
		}
	}
	else {
		for(int i = 0; i < N;i++)
		{
			if(ch[i])continue;
			instruct[sz] = i;
			ch[i] = true;
			dfs(sz+1);
			ch[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>M;
	for(auto i = 0; i < N; i++){
		cin>>input[i];
	}
	sort(input,input+N);
	dfs(0);
}