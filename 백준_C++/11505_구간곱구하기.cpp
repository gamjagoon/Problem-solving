/*
Date : 02/15/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11505
summary : 구간곱 구하기
*/
#include <iostream>
#define endl '\n'
#define mid(a,b) (a + b)>>1
using namespace std;
typedef long long ll;

constexpr ll dumy = 1000000007;
int N,M,K;
ll arr[1000001];
ll tree[4000004];

ll init(int node, int start, int end) {
	if(start == end){
		return tree[node] = arr[start];
	}
	int m = mid(start,end);
	return tree[node] = (init(node*2,start,m)*init(node*2+1,m+1,end)) % dumy;
}

void update(int node,int start, int end,int idx, ll diff, ll ori){
	if(idx < start || idx > end)return;
	if(start != end){
		int m = mid(start,end);
		update(node*2, start, m, idx, diff,ori);
		update(node*2+1, m+1, end, idx, diff,ori);
	}
	if(ori == 0){
		if(start != end){
			tree[node] = (tree[node*2] * tree[node*2+1])%dumy;
		}
		else if(start == end){
			tree[node] = diff;
		}
	}
	else{
		tree[node] /= ori;
		tree[node] *= diff;
		tree[node] %= dumy;
	}
}

ll query(int node,int start,int end, int left,int right) {
	if(left > end || right < start){
		return 1;
	}
	if(left <= start && end <= right) {
		return tree[node];
	}
	int m = mid(start, end);
	return (query( node * 2, start, m,  left, right)*query(node * 2 + 1,m + 1,end,left,right))%dumy;
}


void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	for(int i = 1; i <= N; ++i){
		cin>>arr[i];
	}
}



int main(){
	Input();
	init(1,1,N);
	int t = M + K;
	int a,b,c;
	ll tmp;
	ll ori;
	for(int i = 0 ; i < t; ++i){
		cin>>a>>b;
		if(a == 1){
			ll tmp;
			cin>>tmp;
			ori = arr[b];
			arr[b] = tmp;
			update(1,1,N,b,tmp,ori);
		}
		else{
			cin>>c;
			cout<<query(1,1,N,b,c)<<endl;
		}
	}
}