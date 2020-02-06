/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : 색종이
summary : 구현문제
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;

int n;
bool arr[103][103];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int a,b;
	mfor(i,0,n){
		cin>>a>>b;
		mfor(r,b,b+9){
			mfor(c,a,a+9){
				arr[r][c] = true;
			}
		}
	}
	int res = 0;
	mfor(r,0,101){
		mfor(c,0,101){
			if(arr[r][c])res++;
		}
	}
	cout<<res;
	return 0;
}