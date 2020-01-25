#include <iostream>
using namespace std;

int f[1000001];


int main()
{
	int n;cin>>n;
	if(n == 0)cout<<0;
	else {
		f[1] = 1;
		f[2] = 2;
		for(int i = 3; i <= n; ++i){
			f[i] = f[i-1] % 15746+ f[i-2] % 15746;
		}
		cout<<f[n]% 15746;
	}
}