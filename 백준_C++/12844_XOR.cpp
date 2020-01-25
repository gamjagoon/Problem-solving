#include <iostream>
#define mid(s, e) (s + e)>>1
using namespace std;
typedef long long ll;

inline void mswap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

ll tree[2000004];
ll arr[500001];
ll lazy[2000004];

ll init(int node,int start, int end) {
	if(start == end){
        return tree[node] = arr[start];
    }
    int m = mid(start, end);
    return tree[node] = init(node * 2 + 1, start, m) ^ init(node * 2 + 2, m + 1, end);
}

void update_lazy(int node,int start,int end){
	if(lazy[node] != 0){
		if((end - start +1) % 2 == 1){
			tree[node]^= lazy[node];
		}
		if(start != end){
			lazy[node*2 + 1] ^= lazy[node];
			lazy[node*2+2] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node,int start,int end,int left,int right,ll diff){
	update_lazy(node, start, end);
	if(left > end || right < start)return;
	if(left <= start && end <= right) {
		if((end - start +1) % 2 == 1){
			tree[node]^= diff;
		}
		if(start != end){
			lazy[node*2+1]^= diff;
			lazy[node*2+2]^= diff;
		}
		return;
	}
	int m = mid(start , end);
	update_range( node * 2 + 1, start, m, left, right,diff);
	update_range( node * 2 + 2, m+1, end, left, right, diff);
	tree[node] = tree[node*2+1] ^ tree[node*2+2];
}

ll squery(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
	int m  = mid(start, end);
    return squery(node*2+1, start, m, left, right)^squery(node*2+2, m+1, end, left, right);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0 ; i < n; ++i){
		cin>>arr[i];
	}
	n--;
	init(0,0,n);
	int m;
	cin>>m;
	while(m--){
		int a,b,c;
		ll d;
		cin>>a>>b>>c;
		if(b > c)mswap(b, c);
		if(a == 1){
			cin>>d;
			update_range(0,0,n,b,c,d);
		}
		else{
			cout<<squery(0,0,n,b,c)<<'\n';
		}
	}
}