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