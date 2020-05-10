#include <iostream>
#include <string>
using namespace std;

int result_a, result_b;
string a[51][5];
int N = 0, diff = 35;

inline int line_compare(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < 7; ++i)
		if (a[i] != b[i])cnt++;
	return cnt;
}

int main() {
	cin >> N;
	string tmp;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 5; ++j)
		{
				cin >> tmp;
				a[i][j] = tmp;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int res = 0;
			for (int k = 0; k < 5; ++k) {
				res += line_compare(a[i][k], a[j][k]);
			}
			if (diff > res) {
				diff = res;
				result_a = i;
				result_b = j;
			}
		}
	}
	cout << result_a << ' ' << result_b << endl;
	return 0;
}