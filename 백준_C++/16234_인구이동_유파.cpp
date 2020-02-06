/*
Date : 02/03/2020
version : gcc 6.3.0 c++14
problem : https://www.acmicpc.net/problem/16234
summary : 유니온파인드, 탐색
*/
#include <iostream>
#define endl '\n'
#define mfor(i,s,e) for(auto i = s; i <= e; ++i)
using namespace std;

int N, L, R;
int nation[52][52],id[2600];
int p_cnt[2600], sum_union[2600];
inline int to_index(int x, int y) {
	return x + y * N;
}
int root(int a) {
	if (id[a] != a) return id[a] = root(id[a]);
	return id[a];
}
void make_union(int a,int b) {
	a = root(a);
	b = root(b);
	if (a == b) return;
	id[a] = b;
}
int main() {
	int i, j;
	int idx = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>L>>R;
	for ( i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j,++idx) {
			cin>>nation[i][j];
			id[idx] = idx;
		}
	}
	int ans = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (j < N-1) {
					int d = nation[i][j] - nation[i][j + 1];
					if (d < 0) d = -d;
					if (d >= L && d <= R) make_union(to_index(j, i), to_index(j + 1, i));
				}
				if (i < N - 1) {
					int d = nation[i][j] - nation[i+1][j];
					if (d < 0) d = -d;
					if (d >= L && d <= R) make_union(to_index(j, i), to_index(j, i+1));
				}
			}
		}
		for (i = idx = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				int id = root(idx++);
				sum_union[id] += nation[i][j];
				++p_cnt[id];
			}
		}
		for (i = idx = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				int id = root(idx++);
				nation[i][j] = sum_union[id] / p_cnt[id];
			}
		}
		for (i = idx = 0; i < N; ++i) {
			for (j = 0; j < N; ++j,++idx) {
				if (p_cnt[idx] > 1)  flag = true;
				id[idx] = idx;
				sum_union[idx] = p_cnt[idx] = 0;
			}
		}
		ans += flag;
	}
	cout<<ans;
	return 0;
}