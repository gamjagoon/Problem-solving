#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef pair<int,int>p;
int n;
int id[103];

inline int sub(int a,int b){
	return a > b ? a - b: b - a;
}

inline int len(int x1,int x2,int y1,int y2)
{
	return sub(x1,x2) + sub(y1,y2);
}

int root(int i){
	if(id[i] != i){
		return id[i] = root(id[i]);
	}
	return i;
}

void make_union(int p,int q)
{
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

void init()
{
	vector<p>in;
	cin>>n;
	in.resize(n+2);
	mfor(i,0,n+1){
		cin>>in[i].first>>in[i].second;
		id[i] = i;
	}
	int d = 0;
	mfor(i,0,n+1){
		mfor(j,i,n+1){
			if(len(in[i].first,in[j].first,in[i].second,in[j].second) <= 1000){
				make_union(i,j);
			}
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		init();
		if(root(0) == root(n+1))cout<<"happy\n";
		else cout<<"sad\n";
	}
}