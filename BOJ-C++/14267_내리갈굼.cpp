#include <iostream>
using namespace std;
typedef long long ll;
ll arr[100001];
ll tree[400000];

ll init(int node,int s,int e){
	if(s == e){
		return tree[node] = arr[s];
	}
	int m = (s + e)>>1;
	return tree[node] = init(node*2,s,m)+init(node*2+1,m+1,e);
}

ll squery(int node,int s,int e,int l,int r){
	if(s > r || e < l)return 0;
	if(l <= s && e <= r)return tree[node];
	int m = (s + e) >> 1;
	return squery(node*2,s,m,l,r)+squery(node*2+1,m+1,e,l,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<= n;++i){
		int tmp;cin>> tmp;
		arr[i] = 0;
	}
	while(m--){
		int a,b;cin>> a>> b;
		arr[a] += b;
	}
	init(1,1,n);
	for(int i = 1; i <= n; ++i)
	{
		cout<<squery(1,1,n,1,i)<<' ';
	}
	return 0;
}