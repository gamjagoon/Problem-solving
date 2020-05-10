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

int R,C;
int arr[100][100];

int move_box(int nr,int nc){
	int r = nr + 1;
	int c = nc;
	int cnt = 1;
	while( r < R && arr[r][c] == 0){r++;cnt++;};
	r--;cnt--;
	arr[nr][nc] = 0;
	arr[r][c] = 1;
	return cnt;
}

int main() {
	io;
	int t;cin>>t;
	while(t--){
		cin>>R>>C;
		mfor(r,0,R){
			mfor(c,0,C){
				cin>>arr[r][c];
			}
		}
		int res = 0;
		for(int r = R-1;r >= 0 ;r--){
			mfor(c,0,C){
				if(arr[r][c] == 1){
					res += move_box(r,c);
				}
			}
		}
		cout<<res<<endl;
	}
}