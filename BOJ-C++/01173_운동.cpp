#include <iostream>
using namespace std;
int simul(int N,int m,int M,int T,int R)
{
	int t = 0,now = m,doit = 0;
	while(doit < N){
		if(now + T <= M){
			now+=T;
			t++;
			doit++;
		}
		else{
			if(now - R < m){
				now = m;
			}
			else{
				now-= R;
			}
			t++;
		}
	}
	return t;
}
int main()
{
	int N,m,M,T,R;
	cin>>N>>m>>M>>T>>R;
	if(m==M)cout<<-1;
	else if(m+T > M)cout<<-1;
	else cout<<simul(N,m,M,T,R);
	return 0;
}