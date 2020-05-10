#include<iostream>
#include <algorithm>
using namespace std;
int arr[5000000];
int N, K;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	K--;
	printf("%d", arr[K]);
}