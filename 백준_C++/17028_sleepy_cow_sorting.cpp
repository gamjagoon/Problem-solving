/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : sleepy cow sortin
summary : 소를 정렬하는데 필요한 최소 시간층정
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int arr[101];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;cin>>N;
	mfor(i,0,N-1){
		cin>>arr[i];
	}
	int id = N-1;
	for(int i = N - 2; i >= 0; i--){
		if(arr[i] < arr[i+1])id = i;
		else break;
	}
	cout<<id<<endl;
	return 0;
}