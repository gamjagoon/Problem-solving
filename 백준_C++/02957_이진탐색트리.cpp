#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

map<int,ll>s;
map<int,ll>::iterator iter,lo,hi;
int n,r;
ll c = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int tmp;
	s.insert({0,-1});
	s.insert({300002,-1});
	ll depth;
	while(n--){
		cin>>tmp;
		depth = 0;
		lo = (--s.lower_bound(tmp));
		hi = s.upper_bound(tmp);
		depth = max(lo->second,hi->second)+1;
		c += depth;
		cout<<c<<'\n';
		s.insert({tmp,depth});
	}

}