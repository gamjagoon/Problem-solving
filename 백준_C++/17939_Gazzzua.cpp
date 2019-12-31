#include <iostream>
using namespace std;

typedef long long ll;

ll arr[100001];
ll max_tree[10000100];
const ll Min_value = 0;

inline ll m_max(const ll &a,const ll &b){
	return a > b ? a : b;
}

ll range_maxquery(int s,int e,int l,int r,int node)
{
	if(l <= s && e <= r)return max_tree[node];
	if(e < l || r < s)return Min_value;
	int m = (s + e) >> 1;
	return m_max(range_maxquery (s,m,l,r,node*2),range_maxquery(m+1,e,l,r,node*2+1));
}

void init_max_tree(int node,int s,int e){
	if(s == e){
		max_tree[node] = arr[s];
		return;
	}
	int m = (s + e) >> 1;
	init_max_tree(node*2,s,m);
	init_max_tree(node*2+1,m+1,e);
	max_tree[node] = m_max(max_tree[node*2],max_tree[node*2+1]);
}
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1; i <= N;++i){
		cin>>arr[i];
	}
	init_max_tree(1,1,N);
	ll res = 0,tmp;
	for(int i = 1; i <= N;++i)
	{
		tmp = range_maxquery(1,N,i+1,N,1) - arr[i];
		if(tmp > 0) res+= tmp;
	}
	cout<<res;
	return 0;
}