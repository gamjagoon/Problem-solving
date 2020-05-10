#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int T;cin>>T;
	int res = 1;
	while(T--){
		int tmp;cin>>tmp;
		res += tmp - 1;
	}
	cout<<res;
}
