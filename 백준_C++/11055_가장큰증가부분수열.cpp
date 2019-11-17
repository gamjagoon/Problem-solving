#include<iostream>
using namespace std;
int N, result = 0;
int arr[1000] = { 0 };
int d[1000] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		d[i] = tmp; arr[i] = tmp;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && d[i] < d[j] + arr[i]) {
				d[i] = d[j] + arr[i];
			}
		}
		result = result > d[i] ? result : d[i];
	}
	printf("%d", result);
	return 0;
}