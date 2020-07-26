#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int id[1001],Size[1001];

int root(int u){
	if(u != id[u])return id[u] = root(id[u]);
	return u;
}

void merge(int u, int v){
	u = root(u);
	v = root(v);
	if(u==v) return;
	if(Size[u]>Size[v]) swap(u,v);
	id[u] = v;
	if(Size[u] == Size[v]) ++Size[v];
}


int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	if(m > (n-1)*(n-2)/2){
		cout<<1;
		return 0;
	}
	for(int i=1;i <= n;i++){
		id[i] = i;
		Size[i] = 1;
	}

	int u,v;
	for(int i=0;i<m;++i){
		cin>>u>>v;
		merge(u,v);
	}

	int res=0;
	for(int i=1;i<=n;++i){
		if(i == root(i))res++;
	}
	cout<<res;
	return 0;
}
