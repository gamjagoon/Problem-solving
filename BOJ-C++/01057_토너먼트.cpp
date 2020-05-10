/*
Date : 02/07/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1057
summary : 
*/
#include <iostream>
#include <bitset>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int main(){
	int N,A,B;
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>A>>B;
	if(B < A){
		A ^= B ^= A ^= B;
	}
	bitset<100001>b;
	int t = 0;
	bool End = false;
	while (1)
	{
		t++;
		for(int i = 1; i <N;) {
			if(b[i]){
				i++;
				continue;
			}
			int j = i + 1;
			while(!End && j <= N){
				if(b[j]){
					j++;
					if(j == N+1)End = true;
					continue;
				}
				if(i == A){
					if(j == B){
						End = true;
						break;
					}
					else{
						b[j] = true;
						i = j+1;
						break;
					}
				}
				else if(i == B){
					b[j] = true;
					i = j+1;
					break;
				}
				else{
					b[i] = true;
					i = j+1;
					break;
				}
			}
			if(End)break;
		}
		if(End)break;
	}
	cout<<t<<endl;
}