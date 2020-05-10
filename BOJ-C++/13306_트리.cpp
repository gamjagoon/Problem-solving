#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define INF 1000000009
#define SIZE 200001
#define endl '\n'

using namespace std;

//Global
int N,Q;
int ori[SIZE];
int par[SIZE];
int level[SIZE];
int query[SIZE*2][2];

int find(int v)
{
	if(par[v] == v)return v;
	return par[v] = find(par[v]);
}

void merge(int p,int q)
{
	p = find(p);
	q = find(q);
	if(p == q)return;
	if(level[p] > level[q])swap(p,q);
	par[p] = q;
	if(level[p] == level[q])level[q]++;
}


void solve(int t){
	int a;
	for(int i = 0 ; i < t;i++){
		cin>>a;
		if(a){
			cin>>query[i][0]>>query[i][1];
		}else{
			cin>>query[i][1];
			query[i][0] = 0;
		}
	}
	stack<bool>st;
	for(int i = t-1; i >= 0 ; --i){
		if(query[i][0] != 0){
			if(find(query[i][1]) == find(query[i][0])){
				st.push(true);
			}else st.push(false);
		}else {
			merge(query[i][1],ori[query[i][1]]);
		}
	}
	int sz = st.size();
	for(int i = 0 ; i < sz; ++i){
		st.top() ? cout<<"YES\n" : cout<<"NO\n";
		st.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>Q;
	for(int i = 0 ; i <= N;++i){
		par[i] = i;level[i] = 1;
	}
	int a;
	for(int i = 2; i <= N;i++){
		cin>>a;
		ori[i] = a;
	}
	int t = N-1+Q;
	solve(t);
}
















