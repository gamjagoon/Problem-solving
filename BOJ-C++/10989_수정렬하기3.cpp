#include <stdio.h>
int arr[10001];
int main(){
    int ch,n;
    int max = 1;
	scanf("%d\n",&n);
	for(int i = 0; i < n;++i){
		scanf("%d",&ch);
		arr[ch]++;
		if(ch > max)max = ch;
	}
    int i = 1;
    while(i <= max)
    {
        while( arr[i] != 0){
            printf("%d\n",i);
            arr[i]--;
        }
        i++;
    }
    return 0;
}