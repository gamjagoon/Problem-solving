/*
Date : 03/31/2020
version : gcc 6.3.0 c++14
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define INF 1000000009
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	int c,a,b;
	cin>>c>>a>>b;
	double x = a*a;x += b*b;
	double r = sqrt((double)c*c /x);
	cout<<((int)(r * a))<<' '<<((int)(r * b));
}