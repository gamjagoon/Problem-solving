/*
Date : 02/16/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/9498
summary : 구현
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int result;

void Input(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>result;
}

char Solve(int res){
	char ret;
	if(res >=90){
		ret = 'A';
	}
	else if(res >=80){
		ret = 'B';
	}
	else if(res >= 70){
		ret = 'C';
	}
	else if(res >= 60){
		ret = 'D';
	}
	else{
		ret = 'F';
	}
	return ret;
}

int main(){
	Input();
	cout<<Solve(result)<<endl;
	return 0;
}