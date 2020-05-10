#include <iostream>

using namespace std;

int T;
string ans[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{
		cin>>T;
		if(T == 0)return 0;
		int cnt = T;
		int a = 0;
		int m = T/2;
		if(T % 2 == 1){
			m += 1;
		}
		T -= m;
		while(m--){
			cin>>ans[a];
			a += 2;
		}
		a = 1;
		while(T--){
			cin>>ans[a];
			a += 2;
		}
		for(int i = 0 ; i < cnt;++i){
			cout<<ans[i]<<'\n';
		}
	}
}