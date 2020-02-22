/*
Date : 02/19/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1275
summary : 세그먼트 트리
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define mid(a,b) (a + b)>>1
using namespace std;
typedef long long ll;

constexpr int Max = 100001;
ll arr[Max];
ll tree[Max * 4];

void update(int node, int s,int e,int idx, ll diff){
	if(s <= idx && idx <= e){
		tree[node] += diff;
	}
	else return;
	if(s == e)return;
	int m = mid(s,e);
	update(node*2,s,m,idx,diff);
	update(node*2+1,m+1,e,idx,diff);
}

ll query(int node,int s,int e,int l,int r){
	if(l <= s && e <= r){
		return tree[node];
	}
	if(r < s || e < l)return 0;
	int m = mid(s,e);
	return query(node*2,s,m,l,r) +query(node*2+1,m+1,e,l,r);
}

pair<int,int> Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	mfor(i,1,n){
		cin>>arr[i];
		update(1,1,n,i,arr[i]);
	}
	return {n,q};
}

int main(){
	pair<int,int> p = Input();
	int t = p.second;
	int N = p.first;
	int l,r,pos;
	ll val,diff; 
	t--;
	while(t--){
		cin>>l>>r>>pos>>val;
		if(l > r)swap(l,r);
		cout<<query(1,1,N,l,r)<<endl;
		diff = val - arr[pos];
		arr[pos] = val;
		update(1,1,N,pos,diff);
	}
	cin>>l>>r>>pos>>val;
	if(l > r)swap(l,r);
	cout<<query(1,1,N,l,r)<<endl;
	return 0;
}