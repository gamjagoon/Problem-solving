#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define mfor(a,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

typedef long long ll;
int N,N4;
vector<ll>arr;
vector<ll>tree;

ll query(ll i) {
	ll ret = 0;
	cout<<i<<' ';
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
		cout << i << ' ';
	}
	cout<<'\n';
	return ret;
}

void update(ll i) {
	while (i <= N + 1) {
		tree[i]++;
		i +=(i&-i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N;
	arr.resize(N+1);
	mfor(i,1,N){
		cin>>arr[i];
		tree.push_back(arr[i]);
	}
	sort(tree.begin(),tree.end());
	mfor(i,1,N) arr[i] = lower_bound(tree.begin(),tree.end(),arr[i]) - tree.begin() + 1;
	tree.resize(N+1);
	mfor(i,0,N)tree[i] = 0;
	ll result = 0;
	for (ll i = N; i >= 1; --i)
	{
		result += query(arr[i]-(ll)1);
		update(arr[i]);
	}
	cout<<result;
	return 0;
}