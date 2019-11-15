#include <cstdio>
#include <vector>
using namespace std;

int arr[21][21];
int n, Min_result = 2000;
bool ch[21];

void calc()
{
	vector<int>A;
	vector<int>B;
	for (int i = 1; i <= n; ++i) {
		if (ch[i]) {
			A.push_back(i);
		}
		else {
			B.push_back(i);
		}
	}
	int res = 0;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			res += arr[A[i]][A[j]];
			res -= arr[B[i]][B[j]];
		}
	}
	if (res < 0)res *= -1;
	Min_result = res < Min_result ? res : Min_result;
	return;
}


void dfs(int a,int N) {
	if (a > n || N > n/2)return;
	if (N == n/2) {
		calc();
		return;
	}
	ch[a] = true;
	dfs(a + 1, N + 1);
	ch[a] = false;
	dfs(a + 1, N);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(1,0);
	printf("%d", Min_result);
	return 0;
}