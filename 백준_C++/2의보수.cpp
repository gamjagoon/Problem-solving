#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
	for(ll i = 0 ; i < 100; ++i){
		cout<<i<<'&'<<-i<<'='<<(i&-i)<<'\n';
		
	}
}