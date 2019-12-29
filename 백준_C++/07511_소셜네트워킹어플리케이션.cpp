#include <iostream>
#include <vector>
using namespace std;

int root(vector<int>&id,int i)
{
	if(i != id[i]){
		id[i] = root(id,id[i]);
	}
	return id[i];
}

void MakeUnion(vector<int>&id,vector<int>&sz,int p,int q)
{
	int i = root(id,p);
	int j = root(id,q);
	if(i == j) return;
	if(sz[i] > sz[j]){
		id[j] = i; sz[i] += sz[j];
	}
	else{
		id[i] = j; sz[j] += sz[i];
	}
}

bool IsUnion(vector<int>&id,int p,int q)
{
	int i = root(id,p);
	int j = root(id,q);
	if(i == j)return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	int c = 0;
	cin>>t;
	while(t--)
	{
		c++;
		int n,k,m;
		cin>>n>>k;
		vector<int>id(n);
		vector<int>sz(n);
		for(int i = 0; i < n; ++ i){
			id[i] = i;
			sz[i] = 1;
		}
		int a,b;
		while(k--)
		{
			cin>>a>>b;
			MakeUnion(id,sz,a,b);
		}
		cout<<"Scenario "<<c<<":\n";
		cin>>m;
		while(m--)
		{
			cin>>a>>b;
			if(IsUnion(id,a,b)){
				cout<<"1\n";
			}
			else cout<<"0\n";
		}
		cout<<'\n';
	}
}