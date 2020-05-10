#include <stdio.h>

int tc,low,high,now,t_cnt = 0;
int main(){
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d %d",&low,&high,&now);
		if(now > high){
			printf("#%d -1\n",t_cnt++);
			continue;
		}
		if(now < low){
			printf("#%d %d\n",t_cnt++,low - now);
			continue;
		}
		printf("#%d 0\n",t_cnt++);
	}
	return 0;
}