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
typedef pair<int,int> pii;

array <vector<int>, Max*2+1> g;
array <int, Max*2+1>dfsn,sn;
array <int, Max>res;
array <pii,Max*2> P;
stack<int>st;
int N,M,cnt,sccCnt;

constexpr int notX(int x){ return x%2 ? x-1: x+1; }
constexpr int trueX(int x){ return (x << 1) -1; }
constexpr int falseX(int x){ return x << 1; }

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
		a = (a < 0 ? falseX(-(a+1)) : trueX(a));
		b = (b < 0 ? falseX(-(b+1)) : trueX(b));
		g[notX(a)].push_back(b);
		g[notX(b)].push_back(a);
	}
	mfor(i,0,N*2){
		if(dfsn[i] == 0)dfs(i);
	}
	mfor(i,0,N){
		if(sn[i*2] == sn[i*2+1]){
			cout<<0;
			return 0;
		}
	}
	cout<<1<<endl;
	mfor(i,0,N*2){
		P[i] = pii(sn[i],i);
	}
	sort(P.begin(),P.begin()+N*2);
	res.fill(-1);
	for(int i = N*2-1; i >= 0;i--){
		int tmp = P[i].second;
		if(res[tmp/2] == -1)res[tmp/2] = !(tmp%2);
	}
	mfor(i,0,N){
		cout<<res[i]<< ' ';
	}
	return 0;
}