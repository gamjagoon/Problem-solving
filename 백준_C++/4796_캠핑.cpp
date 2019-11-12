#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	unsigned int test_case = 1;
	while(1){
		scanf("%d %d %d",&a,&b,&c);
		if(a == 0)break;
		int res = 0;
		res+= c/b;
		res*= a;
		c %= b;
		if(c > a){
			res+=a;
		}
		else{
			res+=c;
		}
		printf("Case %d: %d\n",test_case++,res);
	}
	return 0;
}