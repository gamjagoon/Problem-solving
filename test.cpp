#include <iostream>

#define MAX_SIZE 1000

int combination(int n, int r){

	int arr[1000][1000];

	// nCr = (n-1)C(r-1) + (n-1)C(r)
	for(int i=0;i<=n;i++){
		for(int j=0; j<=r;j++){

			if(i==j || j==0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}

	return arr[n][r];

}

int main(){

	printf("%lld", combination(7,4));
	return 0;

}