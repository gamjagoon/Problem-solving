#include <iostream>
#include <cstdio>
using namespace std;

int return_score()
{
	int ch,cnt = 0,res = 0;
	bool flag = false;
	while( (ch = getchar()) != '\n')
	{
		if(ch == 'O')
		{
			flag = true;
			cnt++;
			res+=cnt;
		}
		else{
			flag = false;
			cnt = 0;
		}
	}
	return res;
}

int main()
{
	int N;
	scanf("%d\n",&N);
	while(N--)
	{
		printf("%d\n",return_score());
	}
	return 0;
}