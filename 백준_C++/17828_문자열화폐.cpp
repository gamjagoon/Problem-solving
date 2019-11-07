#include <stdio.h>
#include <string.h>
char A[5000000000];
char B[5000000000];
int main()
{
	int N, X, Z, middle = 0;
	scanf("%d %d", &N, &X);
	memset(A, 'A', N);
	memset(B, 'Z', N);
	if (N * 26 < X || N > X) {
		printf("!");
		return 0;
	}
	else
		{
			X -= N;//A 를 미리 배치
			Z = X / 25;//Z의 갯수를 구한다.
			N -= Z;
			middle = X % 25;//25 배치후 나머지
			if (middle == 0)//중간값 없다
			{
				A[N] = '\0';
				B[Z] = '\0';
				printf("%s%s", A, B);
				return 0;
			}
			else
			{
				N--;
				A[N] = '\0';
				B[Z] = '\0';
				printf("%s", A);
				printf("%c", middle + 'A');
				printf("%s", B);
				return 0;
			}
		}
}