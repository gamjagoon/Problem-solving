/*
Date : 03/04/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/11816
summary : string
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

string str;

void solve(){
	io
	cin>>str;
	if(str[0] != '0'){
		cout<<str<<endl;
	}
	else if(str[1] != 'x'){
		int ret = 0;
		mfor(i,1,str.length()){
			ret *= 8;
			ret += str[i] - '0';
		}
		cout<<ret<<endl;
	}
	else {
		int ret = 0;
		mfor(i,2,str.length()){
			ret *= 16;
			if(str[i]<='f' && str[i] >= 'a'){
				ret += str[i] - 'a' + 10;
			}
			else{
				ret += str[i] - '0';
			}
		}
		cout<<ret<<endl;
	}
}

int main(){
	solve();
}