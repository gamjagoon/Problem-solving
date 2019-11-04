#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, result = 0, s, e;
vector<int>city;
void find_distance() {
	int mid = (s + e) / 2;
	int prev = city[0];
	int now;
	int cnt = 1;
	for (int i = 1; i < N; ++i) {
		now = city[i];
		if (now >= prev + mid) {
			prev = now;
			cnt += 1;
		}
		if (cnt >= C) {
			s = mid + 1;
			result = mid;
			return;
		}
	}
	e = mid - 1;
}


int main() {
	cin >> N >> C;
	int ch, prev = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &ch);
		city.push_back(ch);
	}
	sort(city.begin(), city.end());
	e = city[N - 1] - city[0];
	s = city[1] - city[0];
	while (s <= e) {
		find_distance();
	}
	printf("%d", result);
	return 0;
}