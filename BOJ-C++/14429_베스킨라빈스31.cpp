/*
Date : 03/31/2020
version : gcc 6.3.0 c++14
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	vector<pair<int,int>>res;
	for(int i = 0; i < T; i ++){
		int j,m;
		cin>>j>>m;
		int p = (j-1)/(1+m);
		p++;
		p*=2;
		res.push_back({p,i});
	}
	sort(res.begin(),res.end());
	cout<<res.front().second+1<<' '<<res.front().first<<endl;
}