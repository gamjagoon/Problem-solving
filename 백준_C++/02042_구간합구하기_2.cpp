#include <iostream>
#include <vector>
#define mid(a,b) (a + b) >> 1
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

typedef long long ll;
vector<ll>data;
vector<ll>tree;
vector<ll>lazy;


ll init(int node,int s,int e)
{
	if(s == e){
		return tree[node] = data[s];
	}
	int m = mid(s , e);
	return tree[node] = init(node*2,s,m)+init(node*2+1,m+1,e);
}

void upate_lazy(int node,int s,int e)
{
	if(lazy[node] != 0){
		tree[node]+=(e - s + 1) * lazy[node];
		if(s != e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node,int s,int e,int l,int r,ll dif){
	upate_lazy(node,s,e);
	if(e < l || r < s){
		return;
	}
	if(l <= s && e <= r){
		tree[node] += (e - s +1)*dif;
		if(s != e)
		{
			lazy[node*2] += dif;
			lazy[node*2+1] += dif;
		}
		return;
	}
	int m = mid(s,e);
	update_range(node*2,s,m,l,r,dif);
	update_range(node*2+1,m+1,e,l,r,dif);
	tree[node] = tree[node*2]+tree[node*2+1];
}

ll s_query(int node,int s,int e,int l,int r)
{
	upate_lazy(node,s,e);
	if(l <= s && e <= r){
		return tree[node];
	}
	if(l > e || r < s)return 0;
	int m = (s+e) / 2;
	return s_query(node*2,s,m,l,r) + s_query(node*2+1,m+1,e,l,r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;cin>>N;
	int M;cin>>M;
	int K;cin>>K;
	K+=M;
	data.resize(N+1);
	tree.resize(4*N);
	lazy.resize(4*N);
	mfor(i,1,N){
		cin>>data[i];
	}
	init(1,1,N);
	int a,b,c;
	while(K--)
	{
		cin>>a>>b>>c;
		if(a == 1){
			ll d;
			cin>>d;
			update_range(1,1,N,b,c,d);
		}
		else{
			cout<<s_query(1,1,N,b,c)<<'\n';
		}
	}
}