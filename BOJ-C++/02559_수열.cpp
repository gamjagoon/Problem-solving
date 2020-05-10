#include <iostream>
#include <vector>
using namespace std;

vector<int>res;
vector<int>input;

int update(int node,int s,int e){
	if(s==e){
		return res[node] = input[s];
	}
	int m = ( s + e ) >> 1;
	return res[node] = update(node*2,s,m) + update(node*2+1,m+1,e);
}

int squery(int node,int s,int e,int l,int r){
	if(l > e|| r < s)return 0;
	if(l <= s && e <= r)return res[node];
	int m = (s + e ) >> 1;
	return squery(node * 2 , s, m, l ,r) + squery(node * 2 + 1,m+1 , e, l, r);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N,K;
	cin>>N>>K;
	res.resize(4*N);
	input.resize(N+1);
	for(int i = 1;  i <= N; ++i){
		cin>>input[i];
	}
	update(1,1,N);
	K--;
	int lim = N-K;
	int result = -1000000009;
	for(int i = 1; i <= lim ; i++){
		int curr = squery(1,1,N,i,i+K);
		result = result < curr ? curr : result;
	}
	cout<<result;
}
