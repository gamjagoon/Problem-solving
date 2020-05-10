/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/6064
summary : 카잉달력 유클리드 호제법 이용
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int T,M,N,x,y;

void Input(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
}

int GCD(int a,int b){
	int c;
	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a,int b){
	return a*b / GCD(a, b);
}

int Solve(int end){
	int year = 0;
	for(int i = 0 ; (M*i) + x <= end; ++i){
		int tmp = (M * i + x) % N;
		if(tmp == 0){
			tmp = N;
		}
		if(tmp == y){
			year = M * i + x;
			break;
		}
	}
	if(year != 0)return year;
	else return -1;
}

int main(){
	Input();
	mfor(i,1,T){
		cin>>M>>N>>x>>y;
		int LCM = lcm(M,N);
		cout<<Solve(LCM)<<endl;
	}
	return 0;
}