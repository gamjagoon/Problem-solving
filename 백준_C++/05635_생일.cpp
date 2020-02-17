/*
Date : 02/16/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/5635
summary : 소팅
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

struct peaple{
	string name;
	int d,m,y;
};

int N;
vector<peaple>D;


void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	D.resize(N);
	string tmp;
	int day,mon,ye;
	mfor(i,0,N-1){
		cin>>tmp>>day>>mon>>ye;
		D[i].name = tmp;
		D[i].d = day;
		D[i].m = mon;
		D[i].y = ye;
	}
}

bool com(peaple &a, peaple &b){
	if(a.y == b.y){
		if(a.m == b.m){
			return a.d > b.d;
		}
		return a.m > b.m;
	}
	return a.y > b.y;
}

void Solve(){
	sort(D.begin(),D.end(),com);
	cout<<D.front().name<<endl;
	cout<<D.back().name<<endl;
}

int main(){
	Input();
	Solve();
	return 0;
}