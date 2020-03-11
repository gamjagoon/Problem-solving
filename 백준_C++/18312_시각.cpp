/*
Date : 03/04/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/18312
summary : string
*/
#include <iostream>
#include <cstring>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

bool m_ch[60],s_ch[60];

string itos[60];

void IT(){
	for(char i= 0; i < 60; i++){
		string tmp;
		tmp += i / 10 + '0';
		tmp += i % 10 + '0';
		itos[i] = tmp;
	}
}

int N;
char K;
bool innumber(int i){
	mfor(j,0,2){
		if(itos[i][j] == K){
			return true;
		}
	}
	return false;
}

void solve(){
	cin>>N>>K;
	int ret = 0;
	mfor(i,0,N+1){
		if(innumber(i)){
			ret += 3600;
		}
		else {
			mfor(j,0,60){
				if(innumber(j)){
					ret += 60;
				}
				else {
					mfor(k,0,60){
						if(innumber(k)){
							ret++;
						}
					}
				}
			}
		}
	}
	cout<<ret<<endl;
}

int main(){
	IT();
	solve();
}
