#include <iostream>
using namespace std;
typedef long long ll;

ll f[100];
ll ans[100];

ll func(int n)
{
	if(f[n] != 0)return f[n];
	return f[n] = func(n-1) + func(n-2);
}

int main()
{
	int n;cin>>n;
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= n; ++i){
		func(i);
	}
	ans[1] = 4;
	for(int i = 2; i <= n;++i){
		ans[i] = ans[i-1] + f[i]*2;
	}cout<<ans[n];
}