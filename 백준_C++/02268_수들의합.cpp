/*
Date : 02/19/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/2268
summary : 
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

constexpr int Max = 1000001;
typedef long long ll;

ll arr[Max];
ll tree[Max*4];

inline int mid(int a,int b){
	return (a + b )>> 1;
}

void update(int node,int s,int e,int pos,ll diff){
	if(s <= pos && pos <= e){
		tree[node] += diff;
	}
	else return;
	if(s != e){
		int m = mid(s,e);
		update(node*2,s, m,pos,diff);
		update(node*2+1,m+1,e,pos,diff);
	}
	return;
}

ll query(int node,int s,int e,int l,int r){
	if(l <= s && e <= r){
		return tree[node];
	}
	if(e < l || r < s)return 0;
	int m = mid(s, e);
	return query(node*2,s,m,l,r) + query(node*2+1,m+1,e,l,r);
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N,M;
	cin>>N>>M;
	int a,b,c;
	ll tmp,diff;
	while(M--){
		cin>>a;
		if(a){
			cin>>b>>tmp;
			diff = tmp - arr[b];
			arr[b] = tmp;
			update(1,1,N,b,diff);
		}
		else{
			cin>>b>>c;
			if(b > c)swap(b,c);
			cout<<query(1,1,N,b,c)<<endl;
		}
	}
}