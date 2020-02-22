/*
Date : 02/21/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/10551
summary : 
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

string tmp[4] = {
	"1234567890-=",
	"QWERTYUIOP[]",
	"ASDFGHJKL;\'",
	"ZXCVBNM,./"
};
int pr[12] = {0,1,2,3,3,4,4,5,6,7,7,7};
int s[8];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string input;
	cin>>input;
	for(auto c : input){
		for(int i = 0 ; i < 4; ++i){
			for(int j = 0 ; j < tmp[i].size(); ++j){
				if(tmp[i][j] == c){
					s[pr[j]]++;
				}
			}
		}
	}
	for(auto i : s){
		cout<<i<<endl;
	}
}