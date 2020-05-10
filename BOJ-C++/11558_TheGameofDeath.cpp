/*
Date : 05/02/2020
version : gcc 9.2.0 c++17
decribe : BFS 문제다 
*/
#include <iostream>
#include <array>
#define endl '\n'
#define Loop(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);
#define DEBUG
using namespace std;

array<int,10001>num;
array<bool,10001>ch;
int N;

void init(){
	cin>>N;
	Loop(i,1,N+1){
		cin>>num[i];
		ch[i] = false;
	}
}

int solve(){
	int cnt = 0;
	int cur = 1;
	while (cur != N)
	{
		if(ch[cur])
		{
			return 0;
		}
		ch[cur] = true;
		cnt++;
		cur = num[cur];
	}
	return cnt;
}

int main(){
	io;
	int t;cin>>t;
	while(t--){
		init();
		cout<<solve();
	}
}