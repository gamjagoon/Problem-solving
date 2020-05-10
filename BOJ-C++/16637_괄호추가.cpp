#include <iostream>
using namespace std;
char str[19];
int answer = -2147483648;
int N;
int calc(int a, int b,char sig){
	int sum = 0;
	switch (sig)
	{
	case '+':
		sum = a + b;
		break;
	case '-':
		sum = a - b;
		break;
	case '*':
		sum = a * b;
		break;
	default:
		printf("calc error");
		return -1;
		break;
	}
	return sum;
}
void dfs(int result, int op_idx)
{ 
	int next = 0, now = 0; 
	if (op_idx >= N-1) { 
		if (answer < result) answer = result;
		return;
	}
	now = calc(result, str[op_idx+1], str[op_idx]);
	dfs(now, op_idx+2); 
	if (op_idx + 2 < N-1) 
	{
		next = calc(str[op_idx+1],str[op_idx+3],str[op_idx+2]); 
		now = calc(result, next, str[op_idx]);
		dfs(now,op_idx+4); 
	}
} 
int main(){
	scanf("%d",&N);
	scanf("%s",str);
	for(int i = 0; i < N;i+=2){
		str[i]-=48;
	}
	dfs(str[0],1);
	printf("%d",answer);
	return 0;
}
