#include <vector>
#include <cstdio>
using namespace std;
int n;
char string[19];
int answer = -2147483648;
int calc(int n1,int n2,char op)
{
	int result = 0;
	switch(op){
		case '+':
		result =n1 + n2;
		break;
		case '*':
		result =n1 * n2;
		break;
		case '-':
		result =n1 - n2;
		break;
	}
	return result;
}

void DFS(int result,int op_idx)
{
	int now = 0,next = 0;
	if(op_idx >= n-1)
	{
		if(result > answer) answer = result;
		return;
	}
	//괄호가 없는 경우
	now = calc(result, string[op_idx+1], string[op_idx]);
	DFS(now, op_idx + 2);
	//괄호가 있는 경우
	if(op_idx + 2 < n-1)
	{
		next = calc(string[op_idx+1],string[op_idx+3],string[op_idx+2]);
		now = calc(result, next, string[op_idx]);
		DFS(now, op_idx + 4); 
	}
	
}

int main()
{
	scanf("%d",&n);
	scanf("%s",string);
	for(int i = 0;i < n;i+=2)
	{
		string[i]-= 48;
	}
	DFS(string[0],1);
	printf("%d",answer);
	return 0;
}