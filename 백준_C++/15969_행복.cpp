#include <iostream>
using namespace std;
int Max = 0, Min = 1000, N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int tmp;
		cin >> tmp;
		Max = Max > tmp ? Max : tmp;
		Min = Min < tmp ? Min : tmp;
	}
	printf("%d", Max - Min);
	return 0;
}