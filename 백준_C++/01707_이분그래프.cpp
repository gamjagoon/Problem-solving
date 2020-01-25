#include <iostream>
#include <vector>
using namespace std;

vector<int>list[200001];
int color[200001];
void init(int n,int m){
	for(int i = 1; i <= n;++i){
		list[i].clear();
		color[i] = 0;
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
}
bool isbinary(int n){
	for(auto i: list[n]){
		if(color[i] != 0 && color[i] == color[n]){
			return false;
		}
	}
	return true;
}

void sovle(int n,int m){
	color[n] = m;
	m = m % 2 == 0 ? 1 : 2;
	for(auto i : list[n]){
		if(color[i] == 0){
			sovle(i,m);
		}
	}
}

int main(){
	int t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		init(n,m);
		if(n == 1)cout<<"NO\n";
		else{
			for(int i = 1; i <= n ; ++i){
				if(color[i] == 0){
					sovle(i,1);
				}
			}
			bool flag = false;
			for(int i = 1; i <= n ; ++i){
				if(!isbinary(i)){
					flag = true;
					cout<<"NO\n";
					break;
				}
			}
			if(!flag)cout<<"YES\n";
		}
	}
	return 0;
}