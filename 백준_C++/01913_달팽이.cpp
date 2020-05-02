/*
Date : 05/01/2020
version : gcc 6.3.0 c++14
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int arr[1000][1000];
int resx = 0,resy= 0;
int n,V;
void rotate(int& r,int& c,int& v,int& cnt){
	mfor(i,0,v){
		c++;
		arr[r][c] = cnt;
		if(cnt == V){
			resx = r;resy = c;
		}cnt--;
	}
	mfor(i,0,v){
		r--;
		arr[r][c] = cnt;
		if(cnt == V){
			resx = r;resy = c;
		}cnt--;
	}v--;
	mfor(i,0,v){
		c--;
		arr[r][c] = cnt;
		if(cnt == V){
			resx = r;resy = c;
		}cnt--;
	}
	mfor(i,0,v){
		r++;
		arr[r][c] = cnt;
		if(cnt == V){
			resx = r;resy = c;
		}cnt--;
	}v--;
}

int main(){
	io;
	cin>>n>>V;
	int cnt = n * n;
	int r = 0,c = 0;
	int m = n;
	mfor(i,0,m){arr[r][c] = cnt;
	if(cnt == V){resx = r;resy = c;}
	cnt--;r++;}r--;
	m--;
	while(m > 0) {
		rotate(r,c,m,cnt);
	}
	mfor(r,0,n){
		mfor(c,0,n){
			cout<<arr[r][c]<<' ';
		}cout<<endl;
	}
	cout<<resx+1<<' '<<resy+1;
}