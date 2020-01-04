#include <iostream>
#include <vector>
#define mfor(i,s,e) for(auto i = s; i <= e;++i)
using namespace std;

typedef pair<int,int>p;
bool finded = false;
int N,P,E,l,h,result[20];
vector<p> L;
vector<int>tv;
void dfs(int j)
{
	if(finded) return;
	if(tv.size() == P){
		int lo = 0;int hi = 0;
		for(auto i : tv){
			lo+=L[i].first;
			hi+=L[i].second;
		}
		if(lo <= E && E <= hi){
			E -= lo;
			for(auto i : tv){
				result[i] = L[i].first;
			}
			for(auto i : tv){
				int sub = L[i].second - L[i].first;
				if(sub <= E){
					result[i] += sub;
					E -= sub;
				}
				else{
					result[i] += E;
					E = 0;
				}
			}
			finded = true;
			return;
		}
		else{
			return;
		}
	}
	mfor(i,j,N-1){
		tv.push_back(i);
		dfs(i+1);
		tv.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N>>P>>E;
	mfor(i,0,N-1){
		cin>>l>>h;
		L.push_back(make_pair(l,h));
	}
	dfs(0);
	if(!finded){
		cout<<"-1";
	}
	else{
		mfor(i,0,N-1){
			cout<<result[i]<<' ';
		}
	}
	return 0;
}

