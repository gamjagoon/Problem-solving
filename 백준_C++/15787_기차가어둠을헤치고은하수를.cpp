#include <iostream>
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

constexpr int all_bit = (1<<20)-1;
int memo[21];
int n,m;
int tr[100001];
bool ch[1<<21];

void make_memo(){
	mfor(i,1,20){
		memo[i] = 1<<(i-1);
	}
}

void add_bit(int &a,int b){
	a |= memo[b];
}

void rm_bit(int &a,int b){
	if(a & memo[b]){
		a -= memo[b];
	}
}

void l_shift(int &a){
	a<<=1;
	a &= all_bit;
}
void r_shift(int &a){
	a >>=1;
}

int main()
{
	make_memo();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int a,b,c;
	while(m--){
		cin>>a>>b;
		if(a == 1){
			cin>>c;
			add_bit(tr[b],c);
		}
		else if(a == 2){
			cin>>c;
			rm_bit(tr[b],c);
		}
		else if(a == 3)l_shift(tr[b]);
		else r_shift(tr[b]);
	}
	int res = 0;
	mfor(i,1,n){
		if(!ch[tr[i]]){
			ch[tr[i]]= true;
			res++;
		}
	}
	cout<<res;
	return 0 ;
}