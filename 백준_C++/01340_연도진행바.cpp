/*
Date : 03/04/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/1340
summary : 수학
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i < e; ++i)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

long double notyun = 365*24*3600;
long double trueyun = 366*24*3600;

long long day[13] ={
	0,31*24*60*60,28*24*60*60,31*24*60*60,30*24*60*60,31*24*60*60,30*24*60*60,31*24*60*60,31*24*60*60,30*24*60*60,31*24*60*60,30*24*60*60,31*24*60*60
};

string a[13] = {
	"a","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

void solve(){
	string tmp;
	cin>>tmp;
	long long res = 0;
	int m;
	for(int i= 1;i < 13; ++i){
		if(a[i] == tmp){
			m = i;
			mfor(j,1,m){
				res += day[j];
			}
			break;	
		}
	}
	cin>>tmp;
	long long sum = 0;
	mfor(i,0,2){
		if(tmp[i] == ',')break;
		sum *= 10;
		sum += tmp[i] -'0';
	}
	sum-=1;
	res += sum * 24* 60 * 60;
	cin>>tmp;
	int year = 0;
	mfor(i,0,4){
		year *= 10;
		year += tmp[i] -'0';
	}
	bool yun = false;
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0 )){
		yun = true;
	}
	cin>>tmp;
	sum = 0;
	mfor(i,0,2){
		sum *= 10;
		sum += tmp[i] -'0';
	}
	res += sum * 60 * 60;
	sum = 0;
	mfor(i,3,5){
		sum *= 10;
		sum += tmp[i] -'0';
	}
	res += sum * 60;
	if(yun && m >= 3){
		res += 24*60*60;
	}
	res *= 100;
	auto newres = (long double)res;
	if(yun){
		newres /= trueyun;
	}
	else{
		newres /= notyun;
	}
	cout.precision(15);
	cout<<newres;
}

int main(){
	solve();
}