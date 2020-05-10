/*
Date : 02/19/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/5676
summary : 세그먼트 트리
*/
#include <iostream>
#include <cstring>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define mid(a,b) (a + b)>>1
using namespace std;
typedef long long ll;

int N,K;
int tree[400004];

int update(int node,int s,int e,int val,int idx){
	if(e < idx || idx < s)return tree[node];
	if(s == e){
		return tree[node] = val;
	}
	int m = mid(s,e);
	return tree[node] = update(node * 2, s , m,val,idx) * update(node * 2 + 1, m + 1, e,val,idx);
}

int query(int node,int s, int e,int l,int r){
	if(e < l || r < s)return 1;
	if(l <= s && e <= r)return tree[node];
	int m = mid(s,e);
	return query(node*2,s,m,l,r) * query(node*2+1,m+1,e,l,r);

}

void Init(){
	int tmp;
	mfor(i,1,N){
		cin>>tmp;
		if(tmp > 0){
			update(1,1,N,1,i);
		}
		else if(!tmp){
			update(1,1,N,0,i);
		}
		else update(1,1,N,-1,i);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(cin>>N){
		cin>>K;
		Init();
		char a;
		int b,c,ret;
		while(K--)
		{
			cin>>a>>b>>c;
			if(a=='C'){
				if(c > 0)update(1,1,N,1,b);
				else if(!c)update(1,1,N,0,b);
				else update(1,1,N,-1,b);
			}
			else{
				ret = query(1,1,N,b,c);
				if(!ret)cout<<"0";
				else {
					ret> 0 ? cout<<'+' : cout<<'-';
				}
			}
		}
		cout<<endl;
	}
}