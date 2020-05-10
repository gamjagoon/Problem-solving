//같은 눈이 3개가 나오면 10, 000원 + (같은 눈) * 1, 000원의 상금을 받게 된다.
//같은 눈이 2개만 나오는 경우에는 1, 000원 + (같은 눈) * 100원의 상금을 받게 된다.
//모두 다른 눈이 나오는 경우에는(그 중 가장 큰 눈) * 100원의 상금을 받게 된다.
#include <iostream>
#include <stdio.h>
using namespace std;

int A, B, C;
int main()
{
	cin >> A >> B >> C;
	if (A == B && B == C) {
		printf("%d", 10000 + A * 1000);
	}
	else if (A == B) {
		printf("%d", 1000 + A * 100);
	}
	else if(B==C) {
		printf("%d", 1000 + B * 100);
	}
	else if (A == C) {
		printf("%d", 1000 + A * 100);
	}
	else {
		if (A > C&& A > B)printf("%d", A*100);
		else if (B > C&& B > A)printf("%d", B*100);
		else printf("%d", C*100);
	}
	return 0;
}