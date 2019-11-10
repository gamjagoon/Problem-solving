//첫 줄에 문제의 개수 N, 현정이의 역량 L, 현정이가 대회중에 풀 수 있는 문제의 최대 개수 K가 주어진다.
//둘째 줄부터 N개의 줄에 걸쳐 1 ~N번째 문제의 쉬운 버전의 난이도 sub1, 어려운 버전의 난이도 sub2 가 순서대로 주어진다.
#include <iostream>
using namespace std;
int N, L, K, result = 0;

int main()
{
	cin >> N >> L >> K;
	int sub1, sub2;
	int c_140 = 0, c_100 = 0, c_0 = 0;
	for (int i = 0; i < N; ++i) {
		cin >> sub1 >> sub2;
		if (K == 0)continue;
		if (sub2 <= L) {
			c_140++;
		}
		else if (sub1 <= L) {
			c_100++;
		}
	}
	if (K >= c_140) {
		result += 140 * c_140;
		K -= c_140;
	}
	else {
		printf("%d", 140 * K);
		return 0;
	}
	if (K >= c_100) {
		result += 100 * c_100;
		printf("%d", result);
	}
	else {
		printf("%d", result+100 *K);
	}
	return 0;
}