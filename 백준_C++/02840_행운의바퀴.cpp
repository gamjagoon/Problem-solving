/*
Date : 03/04/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2840
summary : string
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef pair<int,char>pic;

int N,K;
string ret;
bool ch[255];
void solve(){
	io
	cin>>N>>K;
	ret.resize(N);
	mfor(i,0,N){
		ret[i] = '?';
	}
	int S;
	char tmp;
	int pos = 0;
	mfor(i,0,K){
		cin>>S>>tmp;
		S %= N;
		if(pos - S < 0) pos = (pos - S) + N;
		else pos -= S;
		if(ret[pos] != '?' && ret[pos] != tmp){
			cout<<'!'<<endl;
			return;
		}
		else {
			ret[pos] = tmp;
		}
	}
	mfor(i,0,N){
		if(ret[i] == '?')continue;
		if(!ch[ret[i]]){
			ch[ret[i]] = true;
		}
		else{
			cout<<'!'<<endl;
			return;
		}
	}
	mfor(i,0,N){
		cout<<ret[(i+pos)%N];
	}cout<<endl;
}

int main(){
	solve();
}