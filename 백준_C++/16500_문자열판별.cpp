#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
string arr[100], input;
int res = 0, input_len = 0, N;

bool mcompare(int s, int i) {
	for (int j = 0; j < arr[i].length(); ++j) {
		if (arr[i][j] != input[s + j]) {
			return false;
		}
	}
	return true;
}

void dfs(int s) {
	if (s == input_len ) {
		res = 1;
		return;
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (!mcompare(s, i))continue;
			dfs(s + arr[i].length());
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> input;
	input_len = input.length();
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	dfs(0);
	printf("%d", res);
	return 0;
}