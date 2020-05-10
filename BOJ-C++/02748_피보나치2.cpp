#include <iostream>
using namespace std;
long long f[100];

long long func(int n){
    if(f[n] != 0)return f[n];
    else return f[n] = func(n-1) + func(n-2);
}

int main()
{
    int n;cin>>n;
	f[0] = 0;
	if(n == 0)cout<<0;
	else {
    	f[1] = 1;
    	f[2] = 1;
    	cout<<func(n);
	}
}