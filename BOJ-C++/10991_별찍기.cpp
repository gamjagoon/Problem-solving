/*
Date : 03/31/2020
version : gcc 6.3.0 c++14
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int n;

int main() {
	io
	cin>>n;
	if(n == 1){
		cout<<"*";return 0;
	}
	else{
		int l = (n*2 - 2) / 2;
		for(int r = 0 ; r < n;r++){
			int lb = l  - r;
			while(lb--)cout<<' ';
			int m = 2*r+1;
			for(int i = 1; i <= m;i++){
				if(i % 2 == 1){cout<<'*';}
				else cout<<' ';
			}
			cout<<endl;
		}
	}
}