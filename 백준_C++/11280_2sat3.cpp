/*
Date : 02/29/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11097
summary : 2 SAT
*/
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <stack>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

constexpr int Max = 10100;

array <vector<int>, Max*2+1> g;
array <int, Max*2+1>dfsn,sn;
stack<int>st;
int N,M,cnt,sccCnt;

constexpr int notX(int x){ return x ^ 1; }
constexpr int trueX(int x){ return x << 1; }
constexpr int falseX(int x){ return x << 1 | 1; }

int dfs(int here){
	dfsn[here] = ++cnt;
	int ret = dfsn[here];
	st.push(here);
	for(auto i : g[here]){
		if(dfsn[i] == 0){
			ret = min(ret, dfs(i));
		}
		else if(sn[i] == 0){
			ret = min(ret, dfsn[i]);
		}
	}

	if(ret == dfsn[here]){
		sccCnt++;
		while(1){
			int t = st.top();st.pop();
			sn[t] = sccCnt;
			if(t == here)break;
		}
	}
	return ret;
}

int main(){
	io
	cin>>N>>M;
	mfor(i,0,M){
		int a,b;
		cin>>a>>b;
		a = (a < 0 ? falseX(-a) : trueX(a));
		b = (b < 0 ? falseX(-b) : trueX(b));
		g[notX(a)].push_back(b);
		g[notX(b)].push_back(a);
	}
	mfor(i,2,N*2+1){
		if(dfsn[i] == 0)dfs(i);
	}
	bool flag = true;
	mfor(i,1,N+1){
		if(sn[i*2] == sn[i*2+1]){
			cout<<0;
			flag = false;
			break;
		}
	}
	if(flag)cout<<1;
	return 0;
}