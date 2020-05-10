#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100;
int N, M;
vector<int> high[MAX], low[MAX];
bool hch[MAX], lch[MAX];

int dfs(int node)
{
	int result = 1;
	for (int i = 0; i < high[node].size(); i++)
	{
		if (!hch[high[node][i]])
		{
			hch[high[node][i]] = true;
			result += dfs(high[node][i]);
		}
	}
	return result;
}


int dfs2(int node)
{
	int result = 1;
	for (int i = 0; i < low[node].size(); i++)
	{
		if (!lch[low[node][i]])
		{
			lch[low[node][i]] = true;
			result += dfs2(low[node][i]);
		}
	}
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		high[a].push_back(b);
		low[b].push_back(a);
	}
	vector<bool> result(N + 1);
	for (int i = 1; i <= N; i++)
	{
		memset(hch, false, sizeof(hch));
		memset(lch, false, sizeof(lch));
		hch[i] = true, lch[i] = true;
		if (dfs(i) > (N + 1) / 2)result[i] = true;
		if (dfs2(i) > (N + 1) / 2)result[i] = true;
	}
	int cnt = 0;
	for (int i = 0; i < N + 1; i++)
		if (result[i])cnt++;
	cout << cnt << "\n";
	return 0;
}