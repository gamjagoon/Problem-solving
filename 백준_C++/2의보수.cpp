/*
Date : 02/01/2020
version : gcc 8.0.1 c++14
problem : 
summary :
*/
#include <iostream>
#include <bitset>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;


int main()
{
	for(int i = 0 ; i < 100; ++i){
		cout<<i<<endl;
		cout<<"\t"<<bitset<33>(i)<<endl<<"\t"<<bitset<33>(-i)<<endl;
	}
}