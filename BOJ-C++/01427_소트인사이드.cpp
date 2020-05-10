#include <stdio.h>
#include <string.h>

int cnt[11];
void readline()
{
	int ch;
	while ((ch = getchar()) != '\n') {
		cnt[ch - '0']++;
	}
	return;
}
int main() {
	memset(cnt, 0, sizeof(cnt));
	readline();
	for (int i = 10; i > 0; ++i) {
		while (cnt[i] != 0) {
			printf("%d",i);
			cnt[i]--;
		}
	}
	return 0;
}