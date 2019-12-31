#include <stdio.h>
#include <algorithm>

int N,L,a[1001];

int main(){
	scanf("%d %d ",&N,&L);
	for(int i = 0; i < N;++i){
		scanf("%d",a[i]);
	}
	std::sort(a,a+N);
	int tmp = a[0],cnt = 1;
	for(int i = 0 ; i < N; ++i){
		if(tmp + L -1 < a[i])tmp = a[i],cnt++; 
	}
	printf("%d",cnt);
	return 0;
}