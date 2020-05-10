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

int init_min(int node, int s,int e) {
	if (s == e) {
		if (arr[e] != 0) {
			return tree[node].min = arr[s];
		}
		return tree[node].min = MAX;
	}
	int m = mid(s, e);
	return tree[node].min = mmin( init_min(node*2,s,m) , init_min(node*2+1,m+1,e));
}
int init_max(int node, int s,int e) {
	if (s == e) {
		if (arr[e] != 0) {
			return tree[node].max = arr[s];
		}
		return tree[node].max = 0;
	}
	int m = mid(s, e);
	return tree[node].max = mmax( init_max(node*2,s,m) , init_max(node*2+1,m+1,e));
}

int min_query(int node, int s, int e, int l, int r) {
	if(l <= s && e <= r)return tree[node].min;
	if(e < l || r < s)return MAX;
	int m = mid(s, e);
	return mmin(min_query(node*2,s,m,l,r),min_query(node*2+1,m+1,e,l,r));
}

int max_query(int node, int s, int e, int l, int r) {
	if(l <= s && e <= r)return tree[node].max;
	if(e < l || r < s)return 0;
	int m = mid(s, e);
	return mmax(max_query(node*2,s,m,l,r),max_query(node*2+1,m+1,e,l,r));
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
	init_min(1,1,N);
	init_max(1,1,N);
	int a,b;
	mm tmp;
	while (M--) {
		cin>>a>>b;
		cout<<min_query(1,1,N,a,b)<<' '<<max_query(1,1,N,a,b)<<endl;
	}
}