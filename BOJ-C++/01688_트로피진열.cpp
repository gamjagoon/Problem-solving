#include <iostream>
using namespace std;

int  N, cnt_r = 0, cnt_l = 0;
int maximum = 0;
int number[51];
int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int n; cin >> n;
		if (n > maximum) {
			cnt_l++;
			maximum = n;
		}
		number[i] = n;
	}
	maximum = 0;
	for (int i = N; i >= 1; --i) {
		int n = number[i];
		if (n > maximum) {
			cnt_r++;
			maximum = n;
		}
	}
	printf("%d\n%d", cnt_l, cnt_r);
	return 0;
}