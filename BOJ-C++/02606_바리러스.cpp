#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e;++i)
template<typename T1, typename T2>
constexpr auto Min(T1 a, T2  b) { return a>b?b:a; }
using namespace std;

int id[101];
inline void mswap(int& a, int& b) {
	int tmp = a; a = b; b = tmp;
	return;
}
int root(int i) {
	while (id[i] != i) {
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

/*항상 p가 q 보다 작다*/
void make_union(int p, int q)
{
	int i = root(p);
	int j = root(q);
	if(i == j)return;
	if (i > j) {
		id[i] = j;
	}
	else {
		id[j] = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;cin>>N;
	mfor(i,1,N){
		id[i] = i;
	}
	int t; cin>>t;
	int a,b;
	while (t--) {
		cin>>a>>b;
		make_union(a,b);
	}
	int res = 0;
	mfor(i, 2, N) {
		if (root(i) == 1) {
			res++;
		}
	}
	cout<<res;
}
