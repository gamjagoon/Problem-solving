#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
ll tree[3000000];
ll arr[1000001];
int N,M,K;

ll init(int node, int s, int e)
{
	if(s == e){
		return tree[node]  = arr[s];
	}
	int m = (s+e)/2;
	tree[node] = init(node*2, s,m) + init(node*2+1,m+1,e);
	return tree[node];
}

ll m_sum(int node, int l,int r,int s,int e)
{
	if(l <= s && e <= r){
		return tree[node];
	}
	if(r < s || e < l) return 0;
	int m = (s+e)/2;
	return m_sum(node*2,l,r,s,m) + m_sum(node*2+1,l,r,m+1,e);
}

void update(int node,int s,int e,int idx,ll diff)
{
	if(s <= idx && idx <= e)
	{
		tree[node] += diff;
	}
	else 
		return ;
	if(s == e) 
		return;
	int m = (s+e)/2;
	update(node*2, s, m , idx,diff);
	update(node*2+1,m + 1,e,idx,diff);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>M>>K;
	for(int i = 1; i <= N;++i)
	{
		cin>>arr[i];
	}
	init(1,1,N);
	M += K;
	int a,b,c;
	while(M--)
	{
		cin>>a>>b>>c;
		if(a == 1)
		{
			int d = c - arr[b];
			arr[b] = c;
			update(1,1,N,b,d);
		}
		else
		{
			cout<<m_sum(1,b,c,1,N)<<'\n';
		}
	}
	return 0;
}