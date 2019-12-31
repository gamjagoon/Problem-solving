#include <iostream>
#include <vector>
#include <queue>
#define  MAX  1e9+7;
using namespace std;

vector<pair<int, int> >map[1001];
int d[1001] = { 0 };
bool chk[1001] = { false };
int N, s, e;
void init()
{
	cin >> N;
	int M; cin >> M;
	int start, end, cost;
	while (M--)
	{
		cin>> start >> end >> cost;
		map[start].push_back(make_pair(end, cost));
	}
	cin >> s >> e;
}

void calc()
{
	for (int i = 1; i <= N; ++i) {
		d[i] = MAX;
	}
	d[s] = 0; chk[s] = true;
	int now = s;
	for (int aa = 1; aa <=N; ++aa) {
		for (auto k : map[now]) {
			int nxt = k.first;
			int cost = k.second;
			if (!chk[nxt]) {
				if (d[nxt] > d[now] + cost) {
					d[nxt] = d[now] + cost;
				}
			}
		}
		chk[now] = 1;

		int min = 1e9 + 7;
		for (int k = 1; k <= N; ++k) {
			if (!chk[k]) {
				if (d[k] < min) {
					min = d[k];
					now = k;
				}
			}
		}
	}
}

int main()
{
	init();
	calc();
	printf("%d", d[e]);
}