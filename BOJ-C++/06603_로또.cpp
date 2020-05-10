#include <iostream>
using namespace std;

int arr[50];
bool ch[50];

void dfs(int idx,int cnt,int end)
{
	if(cnt == 6){
		for(int i = 0 ; i < end; ++i){
			if(ch[i]){
				cout<<arr[i]<<' ';
			}
		}
		cout<<'\n';
		return;
	}
	else
	{
		for(int i = idx; i < end; i++){
			if(ch[i])continue;
			ch[i] = true;
			dfs(i+1,cnt+1,end);
			ch[i] = false;
		}
	}
}

int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{
		cin>>t;
		if(t == 0)break;
		for(int i = 0 ; i < t; ++i){
			cin>>arr[i];
		}
		dfs(0,0,t);
		cout<<'\n';
	}
}