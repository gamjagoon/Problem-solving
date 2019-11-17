#include <iostream>
#include <vector>
using namespace std;
int N, L, result = 0;
vector<int>col[100];
vector<int>row[100];
void search_line(vector<int>&v,int n,int prev,bool up) {
	if (n >= N)return;
	else {
		if (up) {
			for (int i = n - L; i < n; ++i) {
				if (v[i] != prev) {
					return;
				}
			}
			if (v[n] == prev + 1) {
				if (n == N-1) {
					result++;
					return;
				}
				search_line(v, n + L, prev + 1, true);
				search_line(v, n + 1, prev + 1, false);
			}
			if (v[n] == prev - 1) {
				if (n == N-1) {
					result++;
					return;
				}
				search_line(v, n + L, prev - 1, true);
				search_line(v, n + 1, prev - 1, false);
			}
		}
		else {
			if (prev == v[n]) {
				if (n == N - 1) {
					result++;
					return;
				}
				search_line(v, n + L, prev, true);
				search_line(v, n+1, prev, false);
			}
			else {
				return;
			}
		}
	}
}

void search_line_reverse(vector<int>& v, int n, int prev, bool up) {
	if (n < 0)return;
	// 다리를 놓는 경우 
	else {
		if (up) {
			for (int i = n+L; i > n; --i) {
				if (v[i] != prev) {
					return;
				}
			}
			if (v[n] == prev + 1) {
				if (n == 0) {
					result++;
					return;
				}
				search_line_reverse(v, n - L, prev + 1, true);
				search_line_reverse(v, n - 1, prev + 1, false);
			}
			if (v[n] == prev - 1) {
				if (n == 0) {
					result++;
					return;
				}
				search_line_reverse(v, n - L, prev - 1, true);
				search_line_reverse(v, n - 1, prev - 1, false);
			}
		}
		//다리를 안놓았다
		else {
			if (prev == v[n]) {
				if (n == 0) {
					result++;
					return;
				}
				search_line_reverse(v, n - L, prev, true);
				search_line_reverse(v, n - 1, prev, false);
			}
			else {
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	int tmp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin>>tmp;
			col[i].push_back(tmp);
			row[j].push_back(tmp);
		}
	}
	for (int i = 0; i < col->size(); ++i) {
		int prev = result;
		search_line(row[i], 0, row[i][0], false);
		if (prev != result)printf("row %d prev\n", i);
		if (prev == result) {
			search_line_reverse(row[i], N - 1, row[i][N - 1], false);
			if (prev != result)printf("row %d back\n", i);
		}
		prev = result;
		search_line(col[i], 0, col[i][0], false);
		if (prev != result)printf("col %d prev\n", i);
		if (prev == result) {
			search_line_reverse(col[i], N - 1, col[i][N - 1], false);
			if (prev != result)printf("col %d back\n", i);
		}
	}
	cout << result;
	return 0;
}