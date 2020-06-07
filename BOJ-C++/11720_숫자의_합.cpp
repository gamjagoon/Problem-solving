
/*
Date : 06/07/2020
version : gcc 9.2.0 c++17
problem : https://www.acmicpc.net/problem/11720
summary : math
*/
#include <iostream>
#define endl '\n'
using namespace std;

//Global
char arr[101];
int t;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	cin>>arr;
	int res = 0;
	char * it = std::begin(arr);
	while(t--){
		res += *it++ - '0';
	}
	cout<<res;
}