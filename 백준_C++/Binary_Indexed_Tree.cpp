#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

typedef long long ll;
ll tadd[1000];
ll tmul[1000];
int N;

void update(int i,ll val, ll add)
{
	while(i <= N){
		tadd[i] += val;
		tmul[i] += add;
		i += (i & -i);
	}
}

void range_update(int l,int r,ll by)
{
	update(1,by,-by*(1-l));
	update(r+1,-by,by*r);
}

ll range_query(const int at)
{
	if(at == 0)return 0;
	ll mul = 0, add = 0;
	for(int i = at; i; i -=i&-i){
		mul += tmul[i];
		add += tadd[i];
	}
	return at*mul + add;
}

ll squery(int i)
{
	ll res = 0;
	while(i > 0)
	{
		res += tadd[i];
		i -= (i & -i);
	}
	return res;
}


int main()
{
	cin>>N;
	ll tmp;
	mfor(i,1,N){
		cin>>tmp;
		update(i,tmp,0);
	}
	mfor(i,1,N){
		cout<<squery(i)<<'\n';
	}
	range_update(8,10,10);
	mfor(i,1,N){
		cout<<tadd[i]<<' ';
	}cout<<'\n';
	mfor(i,1,N){
		cout<<tmul[i]<<' ';
	}cout<<'\n';
	cout<<range_query(10)-range_query(8);
}