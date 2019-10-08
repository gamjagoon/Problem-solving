#include <cstdio>
#include <cmath>
int N,y,x;
int result = 0;
int pos;
int main(){
	scanf("%d %d %d",&N,&y,&x);
	int arr,arr_half,pos;
	while(N){
		arr =(int)pow(2,N);
		arr_half = arr/2;
		if(x>=arr_half && y>=arr_half)pos = 3;
		else if(y>=arr_half) pos = 2;
		else if(x>=arr_half) pos = 1;
		else pos = 0;
		result += pos * arr_half *arr_half;
		if(pos==1){
			x-=arr_half;
		}
		else if(pos == 2){
			y-=arr_half;
		}
		else if(pos == 3){
			x-=arr_half;
			y-=arr_half;
		}
		arr = arr_half;
		arr_half = arr/2;
		N--;
	}
	printf("%d",result);
}