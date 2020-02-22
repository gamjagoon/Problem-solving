/*
Date : 02/19/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/14427
summary : 
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define mid(a, b) (a + b) >> 1
using namespace std;


constexpr int Max = 100001;
int N;

int arr[Max];
int tree[Max * 4];

int init(int node,int s,int e){
	if(s == e){
		//홀수
		if(arr[s] % 2){
			return tree[node] = 1;
		}
		return tree[node] = 0;
	}
	int m = (s + e) >> 1;
	return tree[node] = init(node*2,s,m)+init(node*2+1,m+1,e);
}

int query(int node,int s,int e,int l,int r){
	if(r < s || e < l)return 0;
	if(l <= s && e <= r)return tree[node];
	int m = (s + e) >> 1;
	return query(node*2,s,m,l,r)+query(node*2+1,m+1,e,l,r);
}

void update(int node,int s, int e, int pos,int diff){
	if(s > pos || pos > e){
		return;
	}
	if(s == e){
		tree[node] += diff;
		return;
	}
	tree[node] += diff;
	int m = (s + e) >> 1;
	update(node*2,s,m,pos,diff);
	update(node*2+1,m+1,e,pos,diff);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;cin>>N;
	mfor(i,1,N){
		cin>>arr[i];
	}
	init(1,1,N);
	int M;cin>>M;
	int a,b,c,tmp;
	while(M--){
		cin>>a>>b>>c;
		if(a == 3){
			cout<<query(1,1,N,b,c)<<endl;
		}
		else if(a == 2){
			tmp = c - b + 1;
			cout<<tmp - query(1,1,N,b,c)<<endl;
		}
		else{
			if(arr[b] % 2 && c % 2 == 0){
				arr[b] = c;
				update(1,1,N,b,-1);
			}
			else if(arr[b] % 2 == 0 && c % 2){
				arr[b] = c;
				update(1,1,N,b,1);
			}
			else {
				arr[b] = c;
			}
		}
	}
}