#include <iostream>
#include <cmath>

using namespace std;
int A,B,C;
double s,e,res;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>A>>B>>C;
	int tmp = 0;
	int i = 0;
	while(tmp <= C-B){
		i++;
		tmp = A*i;
	}
	i--;
	s = i;
	while(tmp < C+B){
		i++;
		tmp = A*i;
	}
	e = i;
	A = (double)A;
	B = (double)B;
	C = (double)C;
	for(double i = (double)s ; i <= (double)e; i+= 0.000001){
		double ans = A*i;
		ans+= B*sin(i);
		if(ans == C){
			printf("good\n");
			res = i;
			break;
		}
	}
	printf("%f",res);
	return 0;
}