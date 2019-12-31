#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int N, M, A, B;
long long mid, s = 0, e = 1, result;
vector < pair<int, long long > > lend[10001];
bool visit[10001];
bool bfs(int C) {
	queue < int >mq;
	mq.push(A);
	visit[A] = true;
	int x;
	while (!mq.empty()) {
		x = mq.front();
		mq.pop();
		if (x == B)return true;
		int end = lend[x].size();
		for (int i = 0; i < end; ++i) {
			int y = lend[x][i].first;
			int weight = lend[x][i].second;
			if (!visit[y] && weight >= C) {
				visit[y] = true;
				mq.push(y);
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int x, y;
		long long d;
		scanf("%d %d %lld", &x, &y, &d);
		lend[x].push_back(make_pair(y, d));
		lend[y].push_back(make_pair(x, d));
		e = max(e, d);
	}
	result = s;
	cin >> A >> B;
	while (s <= e) {
		memset(visit, false, sizeof(visit));
		mid = s + (e - s) / 2;
		if (bfs(mid)) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	printf("%lld\n", e);
	return 0;
}