#include <iostream>
#define nfor(i,s,e)  for(int i = s; i < e; ++i)
using namespace std;

typedef pair<int,int> p;

int calc_case(int *m,p *truc)
{
	int timeline[101];
	nfor(i,1,101)timeline[i] = 0;
	int s = 101;
	int e = 1;
	nfor(i,0,3){
		if(s > truc[i].first) s = truc[i].first;
		if(e < truc[i].second) e = truc[i].second;
		nfor(j,truc[i].first,truc[i].second){
			timeline[j]++;
		}
	}
	int sum = 0;
	nfor(i,s,e+1)
	{
		sum += m[timeline[i]]*timeline[i];
	}
	return sum;
}

int main()
{
	int rate[4];
	rate[0] = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	nfor(i,1,4){
		cin>>rate[i];
	}
	p t[3];
	nfor(i,0,3){
		cin>>t[i].first>>t[i].second;
	}
	cout<<calc_case(rate,t);
	return 0;
}