#include <stdio.h>

int N;

bool find_num(int n) {
	int tmp = n;
	while (n != 0) {
		tmp += n % 10;
		n /= 10;
	}
	if (tmp == N)return true;
	else return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		if (find_num(i)) {
			printf("%d", i);
			return 0;
		}
		else {
			continue;
		}
	}
	printf("0\n");
	return 0;
}