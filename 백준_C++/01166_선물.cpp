#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
	ll N,L,W,H;
	scanf("%lld %lld %lld %lld",&N,&L,&W,&H);
	long double s = 0, e =100000000.0, m;
	while(e - s > 1e-11){
		m = (s + e)/ 2;
		if( (ll(L/m))*(ll(W/m))*(ll(H/m))<N)e = m;
		else s = m;
	}
	printf("%.10Lf",s);
}
