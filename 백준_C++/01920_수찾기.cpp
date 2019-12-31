#include <stdio.h>
#include <set>
using namespace std;
set<int>s;
int N, M;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		s.insert(tmp);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", s.count(tmp));
	}
	return 0;
}