/*
Date : 02/01/2020
version : gcc 8.0.1 c++14
problem : 
summary :
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;
typedef long long ll;


int main()
{
	for(ll i = 0 ; i < 100; ++i){
		cout<<i<<'&'<<-i<<'='<<(i&-i)<<'\n';
		
	}
}