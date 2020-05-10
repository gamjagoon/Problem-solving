#include<iostream>
using namespace std;

typedef long long ll;
int main()
{
	ll N;
	cin>>N;
	ll res = 0;
	ll k = 9;
	ll numlen = 1;
	ll num = 1;
	while(k < N){
		res+=(k - num + 1) * numlen;
		k = k *10 + 9;
		numlen++;
		num *= 10;
	}
	res += (N - num + 1)*numlen;
	cout<<res;
}