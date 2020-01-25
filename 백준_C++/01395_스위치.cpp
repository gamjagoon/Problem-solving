#include <iostream>
#define mid(s, e) (s + e)>>1
using namespace std;

inline void mswap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int tree[2000004];
int lazy[2000004];

void update_lazy(int node,int start,int end){
	if(lazy[node] != 0){
		if(lazy[node] % 2 == 1){
			tree[node] = (end - start + 1) - tree[node];
		}
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node,int start,int end,int left,int right){
	update_lazy(node, start, end);
	if(left > end || right < start)return;
	if(left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if(start != end){
			lazy[node*2] += 1;
			lazy[node*2+1]+= 1 ;
		}
		return;
	}
	int m = mid(start , end);
	update_range( node * 2 , start, m, left, right);
	update_range( node * 2 + 1, m+1, end, left, right);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int squery(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
	int m  = mid(start, end);
    return squery(node*2, start, m, left, right) + squery(node*2+1, m+1, end, left, right);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		if(b > c)mswap(b, c);
		if(a == 0){
			update_range(1,1,n,b,c);
		}
		else{
			cout<<squery(1,1,n,b,c)<<'\n';
		}
	}
}