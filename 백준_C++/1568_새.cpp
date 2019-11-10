#include <iostream>
using namespace std;
int N, cnt = 0;
inline long long make_num(int n) {
	return n*(n + 1) / 2;
}

void remove_bird() {
	int n = 1;
	while (make_num(n) <= N) {
		n++;
		cnt++;
	}
	n--;
	N -= make_num(n);
}
int main() {
	cin >> N;
	while(N!=0)remove_bird();
	printf("%d", cnt);
	return 0;
}