#include <cstdio>

bool not_self[10001];

void del_number(int n){
	if(n > 10000)return;
	int res = n;
	while(n != 0){
		res+= n%10;
		n/=10;
	}
	if(not_self[res])return ;
	else{
		not_self[res] = true;
		del_number(res);
	}
}
int main(){
	for(int i = 1 ; i <=9977;++i){
		del_number(i);
	}
	for(int i = 1; i <= 10000;++i){
		if(!not_self[i])printf("%d\n",i);
	}
	return 0;
}