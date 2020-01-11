#include <iostream>
#define mid(s,e) (s + e)>>1
#define MAX 1000000001
#define endl '\n'
using namespace std;

typedef struct mm {
	int min,max;
}mm;
mm tree[400000];
mm dumi;
int arr[100001];
int N, M;

void memnset(void* p, int val, int sz) {
	int*ptr = (int *)p;
	for (int i = 0; i <= sz; ++i) {
		*ptr = val;
		ptr++;
	}
}


inline int mmin(const int & a,const int& b) {
	if(a> b)return b;
	else return a;
}

inline int mmax(const int& a,const int& b) {
	if (a > b)return a;
	else return b;
}

mm goodnode(const mm& a,const mm& b) {
	mm ret;
	ret.max = mmax(a.max,b.max);
	ret.min = mmin(a.min,b.min);
	return ret;
}

mm init(int node, int s,int e) {
	if (s == e) {
		if (arr[e] != 0) {
			mm tmp;
			tmp.max = arr[s];
			tmp.min = arr[s];
			return tree[node] = tmp;
		}
		return tree[node] = dumi;
	}
	int m = mid(s, e);
	tree[node].max = mmax( init(node*2,s,m).max , init(node*2+1,m+1,e).max);
	tree[node].min = mmin( init(node*2,s,m).min , init(node*2+1,m+1,e).min);
	return tree[node];
}

mm query(int node, int s, int e, int l, int r) {
	if(l <= s && e <= r)return tree[node];
	if(e < l || r < s)return dumi;
	int m = mid(s, e);
	return goodnode(query(node*2,s,m,l,r),query(node*2+1,m+1,e,l,r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for (int i = 1; i <= N; ++i)
	{
		cin>>arr[i];
	}
	dumi.max = 0;
	dumi.min = MAX;
	init(1,1,N);
	int a,b;
	mm tmp;
	while (M--) {
		cin>>a>>b;
		tmp = query(1, 1, N, a, b);
		cout<<tmp.min<<' '<<tmp.max<<endl;
	}
}