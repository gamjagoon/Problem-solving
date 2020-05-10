/*
Date : 02/01/2020
version : gcc 6.3.0 c++14
problem : 보석도둑
summary : 그리디 + priority_queue
*/
#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;
typedef struct point{
	int m,cost;
}p;

int N,K;
multiset<int>myset;
p ju[300000];

bool com_1(const p &a,const p &b){
	if(a.cost == b.cost){
		return a.m > b.m;
	}
	else{
		return a.cost > b.cost;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>K;
	int sz,co;
	mfor(i,0,N-1){
		cin>>sz>>co;
		ju[i].cost = co;
		ju[i].m = sz;
	}
	mfor(i,0,K-1){
		cin>>sz;
		myset.insert(sz);
	}
	p tmp;
	ll res = 0;
	sort(ju,ju+N,com_1);
	mfor(i,0,N-1)
	{
		auto now = myset.lower_bound(ju[i].m);
		if(*now >= ju[i].m && !myset.empty()){
			res += ju[i].cost;
			myset.erase(now);
		}
		else if(myset.empty())break;
	}
	cout<<res;
	return 0;
}