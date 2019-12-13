#include <iostream>
#define RBIT 0b100000
#define LBIT 0b10
#define TBIT 0b10000000
#define BBIT 0b1
using namespace std;
int poly[4];
void init()
{
	ios::sync_with_stdio(false);cin.tie(0);
	for(int i = 0 ; i < 4;++i)
	{
		string tmp;
		cin>>tmp;
		int bi = 0;
		for(int j = 0; j < 8;++j){
			bi<<=1;
			if(tmp[j] == '1')
			{
				bi+=1;
			}
		}
		poly[i] = bi;
	}
}

void rotate(int n,int dir)
{
	int now = poly[n];
	if(dir < 0)
	{
		int tmp = now&TBIT;
		tmp>>=7;
		now<<=1;
		now&=0b11111111;
		now|=tmp;
	}
	else
	{
		int tmp = now&BBIT;
		tmp<<=7;
		now>>=1;
		now|=tmp;
	}
	poly[n] = now;
}

bool return_R(int n)
{
	if(poly[n] & RBIT){
		return true;
	}
	else return false;
}

bool return_L(int n)
{
	if(poly[n] & LBIT){
		return true;
	}
	else return false;
}

int main()
{
	init();
	int t;cin>>t;
	int a,b;
	while(t--)
	{
		cin>>a>>b;
		a--;
		bool nr,nl;
		switch (a)
		{
		case 0:
			nr = return_R(a);
			rotate(a,b);
			while(a < 4)
			{
				a++;
				b*=-1;
				if(nr != return_L(a)){
					nr = return_R(a);
					rotate(a,b);
				}
				else{
					break;
				}
			}
			break;
		case 1:
			nr = return_R(a);
			nl = return_L(a);
			rotate(a,b);
			if(nl != return_R(0))rotate(0,b*-1);
			if(nr != return_L(2)){
				nr = return_R(2);
				rotate(2,b*-1);
				if(nr != return_L(3)){
					rotate(3,b);
				}
			}
			break;
		case 2:
			nr = return_R(a);
			nl = return_L(a);
			rotate(a,b);
			if(nr != return_L(3))rotate(3,b*-1);
			if(nl != return_R(1)){
				nl = return_L(1);
				rotate(1,b*-1);
				if(nl != return_R(0)){
					rotate(0,b);
				}
			}
			break;
		default:
			nl = return_L(a);
			rotate(a,b);
			while(a >= 0)
			{
				a--;
				b*=-1;
				if(nl != return_R(a)){
					nl = return_L(a);
					rotate(a,b);
				}
				else{
					break;
				}
			}
			break;
		}
	}
	int cnt = 0;
	for(int i = 0 ; i < 4;++i)
	{
		if(poly[i] & TBIT){
			cnt += 1<<i;
		}
	}
	cout<<cnt;
	return 0;
}