#include <cstdio>
#include <cmath>
int test_case,K,N,case_cnt = 1;
int arr[513];
int main(){
	scanf("%d",&test_case);
	while(test_case--){
		long long result = 0;
		scanf("%d",&K);
			N = (int)pow(2,K-1);
			for(int i = 0; i < N;++i){
				int a,b;
				int tmp;
				scanf("%d %d",&a,&b);
				if(a > b){
					tmp = a-b;
					arr[i] = a ;
				}
				else{
					tmp = b - a;
					arr[i] = b;
				}
				result+=tmp;
			}
			while(1){
				N /=2;
				if(N == 0)break;
				for(int i = 0 ; i < N;++i){
					int a = arr[i*2];
					int b = arr[i*2+1];
					int tmp;
					if(a > b){
						tmp = a - b;
						arr[i] = a;
					}
					else{
						tmp = b - a;
						arr[i] = b;
					}
					result += tmp;
				}
			}
		
		printf("#%d %lld\n",case_cnt,result);
		case_cnt++;
	}
	return 0;
}