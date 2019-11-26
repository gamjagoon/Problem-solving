#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int MAX = INTMAX_MAX;
int d[1001];
vector<pair<int, int> >map[1001];
queue<int>q;
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
	d[s] = 0;
	q.push(s);

}

int main()
{
	init();
	calc();
	printf("%d", d[e]);
}