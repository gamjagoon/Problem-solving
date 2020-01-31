#include <iostream>
using namespace std;

bool ch[2000001];
int N, arr[20];

void dfs(int prev,int sum){
	int tmp;
	for(int i = prev+1;i < N;++i){
		tmp = sum+arr[i];
			ch[tmp] = true;
			dfs(i,tmp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N; ++i){
		cin>>arr[i];
		ch[arr[i]] = true;
	}
	for(int i = 0 ; i < N;++i){
		dfs(i,arr[i]);
	}
	for(int i = 1; i <= 2000000;++i){
		if(!ch[i]){
			cout<<i;
			break;
		}
	}
	return 0;
}