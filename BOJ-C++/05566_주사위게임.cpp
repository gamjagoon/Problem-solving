#include <iostream>
using namespace std;

int N, M, map[1001];

int main() {
	cin >> N >> M;
	int now = 1, time = 0, result = 1e9;
	for (int i = 1; i <= N; ++i) {
		cin >> map[i];
	}
	for (time= 1; time <= M; ++time) {
		int tmp; cin >> tmp;
		now += tmp;
		//printf("%d %d %d ",tmp, now, map[now]);
		if (now >= N) {
			printf("%d", time);
			return 0;
		}
		else {
			now += map[now];
			if (now >= N) {
				printf("%d", time);
				return 0;
			}
		}
	}
	printf("%d", M);
	return 0;
}