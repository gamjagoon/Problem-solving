#include <iostream>
using namespace std;

int N;
int output[101], input[101];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> input[i];
	}
	output[1] = input[1];
	if (N == 1)cout << output[1];
	else {
		cout << output[1] << ' ';
		long long prev = (long long)output[1];
		for (int j = 2; j <= N; ++j) {
			long long now = (long long)input[j] * j;
			cout << now - prev << ' ';
			prev = now;
		}
	}
	return 0;
}