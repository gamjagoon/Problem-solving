#include <iostream>
#include <vector>
#include <algorithm>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
#define mid(s,e) (s + e)>>1
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;

int tree[2000000] = {0,};
vector<pii>arr;
pii id[1000001];
ll result = 0;	

int squery(int node,int s,int e,int l,int r){
	if(r < s || e < l)return 0;
	if(s==e)return tree[node];
	if(l <= s && e <= r)return tree[node];
	int m = mid(s,e);
	return squery(node*2,s,m,l,r)+squery(node*2+1,m+1,e,l,r);
}

void update(int node,int s,int e,int pos){
	if(pos < s || e < pos)return ;
	if(s == e){
		tree[node] += 1;
		return;
	}
	int m = mid(s,e);
	update(node*2,s,m,pos);
	update(node*2+1,m+1,e,pos);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
	int n,tmp;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	arr.reserve(n);
	mfor(i,1,n){
		cin>>tmp;
		id[tmp].second = i;
	}
	mfor(i,1,n){
		cin>>tmp;
		id[tmp].first = i;
	}
	mfor(i,0,1000000){
		if(id[i].first != 0)
			arr.push_back(pii(id[i].first,id[i].second));
	}
	sort(arr.begin(),arr.end());
	for(auto v : arr){
		result += (ll)squery(1,1,n,v.second,n);
		update(1,1,n,v.second);
	}
	cout<<result;
	return 0;
}