#include <iostream>
#include <algorithm>

typedef struct str {
	char* first;
}str;
str data[8];
int input[8], instruct[8], M, N;
bool ch[8];
char str_data[8][6];

void init() {
	for (int i = 0; i < N; ++i) {
		char a[6];
		int x = input[i];
		size_t b = 0;
		while (x) {
			a[b++] = x % 10 + 48;
			x /= 10;
		}
		for (int j = 0; j< b; ++j) {
			str_data[i][j] = a[b-1-j];
		}
		str_data[i][b] = '\0';
		data[i].first = str_data[i];
	}
}
void dfs(int D) {
	if (D == M) {
		for (int i = 0; i < M; ++i) {
			printf("%s ", data[instruct[i]].first);
		}
		printf("\n");
		return;
	}
	int old = 0;
	for (int i = 0; i < N; ++i) {
		if (!ch[i] && (!i||old != input[i])) {
			instruct[D] = i;
			old = input[i];
			ch[i] = true;
			dfs(D + 1);
			ch[i] = false;
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; ++i) {
		scanf("%d", &input[i]);
	}
	std::sort(input, input+N);
	init();
	dfs(0);
	return 0;
}