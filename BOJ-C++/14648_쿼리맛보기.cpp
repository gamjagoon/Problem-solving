#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int N,q;
int k,a,b,c,d;
ll arr[1001];
ll tree[10001];

void m_swap(ll &a,ll &b){
	ll tmp = a;
	a = b;
	b = tmp;
}

void update(int node,int s,int e,int idx,ll diff)
{
	if(idx < s || e < idx)return;
	tree[node] += diff;
	int m = (s + e)>>1;
	if(s != e){
		update(node*2,s,m,idx,diff);
		update(node*2+1,m+1,e,idx, diff);
	}
}


ll squery(int node,int s,int e,int l,int r)
{
	if(l > e || r < s) return 0;
	if(l <= s && e <= r){
		return tree[node];
	}
	int m = (s+e)>>1;
	return squery(node*2,s,m,l,r)+squery(node*2+1,m+1,e,l,r);
}

ll init(int node,int s, int e)
{
	if(s == e){
		return tree[node] = arr[s];
	}
	int m = (s + e)>>1;
	return tree[node] = init(node*2,s,m) + init(node*2+1,m+1,e);
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>q;
	for(int i = 1; i <= N;++i)
	{
		cin>>arr[i];
	}
}


int main()
{
	input();
	memset(tree,0,sizeof(tree));
	init(1,1,N);
	while(q--){
		cin>>k;
		if(k == 1){
			cin>>a>>b;
			cout<<squery(1,1,N,a,b)<<'\n';
			ll d_ba = arr[b]-arr[a];
			ll d_ab = arr[a]-arr[b];
			m_swap(arr[a],arr[b]);
			update(1,1,N,a,d_ba);
			update(1,1,N,b,d_ab);
		}
		else{
			cin>>a>>b>>c>>d;
			cout<<squery(1,1,N,a,b) - squery(1,1,N,c,d)<<'\n';
		}
	}
}