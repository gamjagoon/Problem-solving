#include <iostream>

using namespace std;
string A;
int len;
int K = 0, result = 0;
int c[2] = { 4,7 };
int ch[9] = { 0};
void dfs(int n)
{
	if (n == len) {
		int tmp = 0;
		for (int i = 0; i < n; ++i) {
			tmp *= 10;
			tmp += c[ch[i]];
		}
		if (tmp <= K && result < tmp) {
			result = tmp;
		}
		else return;
	}
	else {
		ch[n] = 1;
		dfs(n + 1);
		ch[n] = 0;
		dfs(n + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A;
	len = A.length();
	for (int i = 0; i < len; ++i)
	{
		K *= 10;
		K += (A[i] - '0');
	}
	if (A[0] < '4')len--;
	dfs(0);
	if (result == 0) {
		len--;
		dfs(0);
	}
	printf("%d", result);
}