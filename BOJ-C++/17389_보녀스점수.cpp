#include <iostream>
using namespace std;

int N, result, bonus = 0;

int main() {
	cin >> N;
	char prev;
	cin >> prev;
	if (prev == 'O') {
		result = 2;
		bonus = 1;
	}
	else result = 0;
	for (int i = 2; i <= N; ++i) {
		char now;
		cin >> now;
		if (now == 'O') {
			if (prev != now) {
				bonus = 0;
			}
			else bonus++;
			result += (i + bonus);
			prev = now;
		}
		else {
			bonus = 0;
			prev = now;
		}

	}
	printf("%d", result);
}