#include <iostream>
using namespace std;
int n,m;
int id[1001];

int root(int i){
	if(id[i] != i){
		return id[i] = root(id[i]);
	}
	return i;
}

void merge(int p, int q){
	int i = root(p);
	int j = root(q);
	if(i == j)return;
	if(i < j){
		id[j] = i;
	}
	else{
		id[i] = j;
	}
}
bool ch[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n ;++i){
		id[i] = i;
	}
	int a,b;
	for(int i = 0 ; i < m ; ++i){
		cin>>a>>b;
		merge(a,b);
	}
	int res = 0;
	int tmp;
	for(int i = 1 ; i <= n;++i){
		tmp = root(i);
		if(!ch[tmp]){
			ch[tmp] = true;
			res++;
		}
	}
	cout<<res;
	return 0;
}