#include <stdio.h>
int N;
int main()
{
	scanf("%d\n", &N);
	int ch, result = 0;
	while ((ch = getchar()) != '\n') {
		result += ch;
	}
	printf("%d", result - '0' * N);
}