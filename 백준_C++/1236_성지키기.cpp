#include <iostream>
using namespace std;

int R, C, cnt = 0, cnt2 = 0;
bool man_r[51];
bool man_c[51];
int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			char tmp;
			cin >> tmp;
			if (tmp == 'X') {
					man_c[j] = true;
					man_r[i] = true;
			}
		}
	}
	for (int i = 1; i <= R; ++i) {
		if (!man_r[i])
			cnt++;
	}
	for (int i = 1; i <= C; ++i) {
		if (!man_c[i])
			cnt2++;
	}
	int res = cnt > cnt2 ? cnt : cnt2;
	printf("%d", res);
	return 0;
}