#include <iostream>
#include <vector>
#include <map>
#define INF 1000000009
#define endl '\n'
using namespace std;

map<string,int>W;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		W.clear();
		int n;cin>>n;
		string name,where;
		for(int i = 0 ; i < n; ++i){
			cin>>name>>where;
			if(W.count(where)){
				W[where]++;
			}else{
				W[where] = 2;
			}
		}
		int res = 1;
		for(auto i : W){
			res*=i.second;
		}
		res--;
		cout<<res<<endl;
	}
}
