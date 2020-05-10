#include <cstdio>
#define sum(X) (X.num[0] + X.num[1] + X.num[2] + X.num[3])
typedef struct money{
	int num[4]; //c, n, d, q;
} money;

//dp[cost]는 idx 종류의 동전으로 cost원을 만들때 max동전수와 그 구성을 기록

int main()
{
	money dp[10010];
	for(int i=0;i<10010;i++)
	{
		dp[i].num[0] = dp[i].num[1] = dp[i].num[2] = dp[i].num[3] = 0;
	}
	int x; scanf("%d",&x);
	int arr[4];
	int coin[4] = {1,5,10,25};
	for(int i=0;i<4;i++) scanf("%d",&arr[i]);
	for(int i=0;i<1;i++)
	{
		for(int j=1;j<=arr[0] && j*coin[0]<=x;j++)
		{
			dp[j*coin[0]].num[0] = j;
		}
	}
	for(int i=1;i<4;i++)
	{
		for(int j=coin[i];j<=x;j++)
		{
			if(dp[j-coin[i]].num[i] < arr[i])//coin을 value 오름차순으로 정렬했으니 갱신하는게 이득이라는 말은 이번 동전 없이는 못만든다는 뜻이므로 항상 갱신하는게 옳다
		{
			int a = sum(dp[j-coin[i]]);
			int b = sum(dp[j]);
			if(a+1 > b && ((a!=0)||(j==coin[i])))
			{
				dp[j] = dp[j-coin[i]];
				dp[j].num[i]++;
			}
		}
	}
}
for(int i=0;i<4;i++)
	printf("%d ",dp[x].num[i]);
}
