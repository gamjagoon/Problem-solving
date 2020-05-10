#include <iostream>
using namespace std;
int now = 0, N, T, time = 210, result = 0;
char Z;

inline int next_num(int n) {
	if (n == 8)return 1;
	else return n + 1;
}
int main() {
	cin >> now;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> T >> Z;
		time -= T;
		if (time < 0) {
			result = now;
			continue;
		}
		else if (Z == 'N') {
			result = now;
			continue;
		}
		else if (Z == 'T') now = next_num(now);
	}
	printf("%d", now);
	return 0;
}