#include <iostream>
#include <vector>
using namespace std;

vector<int>v[99];
int res = 0;

void input(int n){
	int from, to;
	res = 0;
	for(int i = 0 ; i < 99;++i){
		v[i].clear();
	}
	for(int i = 0 ; i <n;++i){
		cin>>from>>to;
		v[from].push_back(to);
	}
}

void dfs(int to){
	if(to == 99){
		res = 1;
		return;
	}
	else if(!v[to].empty() || res != 1){
		for(int i = 0 ; i < v[to].size(); ++i){
			dfs(v[to][i]);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc,tmp;
	for(int T = 1; T <= 10; ++T){
		cin>>tc>>tmp;
		input(tmp);
		for(int i = 0 ; i < v[0].size();++i){
			dfs(v[0][i]);
		}
		cout<<'#'<<tc<<' '<<res<<'\n';
	}
	return 0;
}