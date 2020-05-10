/*
Date : 02/14/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/3758
summary : 정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int n,k,tid;

struct team{
	int point,cnt,last,tnum;
	int ch[101];
};

vector<team> T;

void Input(){
	int m;
	cin>>n>>k>>tid>>m;
	T.clear();
	mfor(i,0,n){
		T.push_back({0,0,10001,i,{0,}});
	}
	int a,b,c;
	int t  = 0;
	while (m--)
	{
		t++;
		cin>>a>>b>>c;
		T[a].cnt++;
		T[a].last = t;
		if(T[a].ch[b] < c){
			T[a].ch[b] = c;
		}
	}
	for(auto i = 1; i < T.size(); ++i){
		mfor(j,1,k){
			T[i].point += T[i].ch[j];
		}
	}
}

bool com(team &A,team&B){
	if(A.point == B.point){
		if(A.cnt == B.cnt)return A.last < B.last;
		return A.cnt < B.cnt;
	}
	return A.point > B.point;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc;cin>>tc;
	while(tc--){
		Input();
		auto s = T.begin();
		s++;
		sort(s,T.end(),com);
		int sz = T.size();
		for(int i = 1; i < sz; ++i){
			if(T[i].tnum == tid){
				cout<<i<<endl;
			}
		}
	}
}