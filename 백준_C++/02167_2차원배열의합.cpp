/*
Date : 05/02/2020
version : gcc 9.2.0 c++17
decribe : 2차원 다이나믹 프로그래밍 
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int R,C;
int arr[301][301];
int srr[301][301];

int main() {
	io;
	cin>>R>>C;
	mfor(r,1,R+1){
		mfor(c,1,C+1){
			cin>>arr[r][c];
			srr[r][c] = arr[r][c];
		}
	}
	mfor(r,1,R){srr[r+1][1] +=srr[r][1];}
	mfor(c,1,C){srr[1][c+1] +=srr[1][c];}
	mfor(r,1,R){
		mfor(c,1,C){
			srr[r+1][c+1] += srr[r+1][c] + srr[r][c+1] - srr[r][c];
		}
	}
	int t;cin>>t;
	while(t--){
		int i,j,r,c;
		cin>>i>>j>>r>>c;
		cout<<srr[r][c] + srr[i-1][j-1] - srr[i-1][c] - srr[r][j-1]<<'\n';
	}
}