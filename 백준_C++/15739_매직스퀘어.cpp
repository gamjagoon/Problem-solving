/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : 매직스퀘어
summary : 구현
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
int val;
int raw[101];
int across[2];
bool ch[10001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	bool flag = true;
	val = n * (n * n  + 1) / 2;
	int tmp;
	int cal;
	mfor(r,1,n){
		cal = 0;
		mfor(c,1,n){
			cin>>tmp;
			if(!flag)continue;
			if(ch[tmp]){
				flag = false;
				continue;
			}
			else {
				ch[tmp] = true;
			}
			cal += tmp;
			raw[r] += tmp;
			if(r == c)across[0] += tmp;
			if(r + c == n + 1)across[1] += tmp;
		}
		if(cal != val)flag = false;
	}
	if(!flag)cout<<"FALSE";
	else {
		mfor(i,1,n){
			if(val != raw[i]){
				flag = false;
				break;
			}
		}
		if(!flag)cout<<"FALSE";
		else{
			mfor(i,0,1){
				if(val != across[i]){
					flag = false;
					break;
				}
			}
			if(!flag)cout<<"FALSE";
			else cout<<"TRUE";
		}
	}
	return 0;
}