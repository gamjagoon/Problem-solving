#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int N, M, K, result = 5000;
int arr[51][51], ori_arr[51][51];
int krr[6][3];
int board[6] = {0,1,2,3,4,5 };
bool ch[6];


void doit(int x, int y, int r) {
	int key_1 = arr[y - r][x + r];
	int key_2 = arr[y + r][x - r];
	for (int i = x + r; i > x - r; --i)arr[y - r][i] = arr[y - r][i - 1];
	for (int i = x - r; i < x + r; ++i)arr[y + r][i] = arr[y + r][i + 1];
	for (int j = y - r; j < y + r - 1; ++j)arr[j][x - r] = arr[j + 1][x - r];
	for (int j = y + r; j > y - r + 1; --j)arr[j][x + r] = arr[j - 1][x + r];
	arr[y + r - 1][x - r] = key_2;
	arr[y - r + 1][x + r] = key_1;
}

void func1() {
	int cnt = result;
	for (int i = 1; i <= N; ++i) {
		int tmp = 0;
		for (int j = 1; j <= M; ++j) {
			tmp += arr[i][j];
		}
		result = result < tmp ? result : tmp;
	}
}

void permu(int n) {
	if (n == K) {
		for (int i = 0; i < K; ++i) {
			int x = krr[v[i]][1];
			int y = krr[v[i]][0];
			int r = krr[v[i]][2];
			while (r >= 1) {
				doit(x, y, r);
				r--;
			}
		}
		func1();
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				arr[i][j] = ori_arr[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < K; ++i) {
			if (!ch[i]) {
				ch[i] = true;
				v.push_back(board[i]);
				permu(n + 1);
				v.pop_back();
				ch[i] = false;
			}
		}
	}
}

int main() {
	
	cin >> N >> M >> K;
	v.reserve(6);
	for (int i = 1; i <= N;++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &arr[i][j]);
			ori_arr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &krr[i][j]);
		}
	}
	permu(0);
	printf("%d", result);
	return 0;
}