#include <stdio.h>
#include<stdlib.h>

int main() {
	int N;
	int a[100];
	char b[100];
	int sum = 0;
	scanf("%d", &N);
	scanf("%[^\n]", b);
	
	for (int k = 0; k < N; k++) {
		for (int i = 0; i <= k-1; i++) {
			sum += a[i];
		}
		a[k] =(k+1) * (b[k]-'0') - sum;
		sum = 0;
	}
	
	for (int i = 0; i < N;i++) {
		printf("%d", a[i]);
	}
}