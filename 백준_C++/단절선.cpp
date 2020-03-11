#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;
constexpr int Max = 100000;

int V, E, dcnt, dfsn[Max];
vector<int> g[Max];
stack<pii> S;
vector<vector<pii>> bcc;

int Dfs(int curr,int prev = -1)
{
	int res = dfsn[curr] = ++dcnt;
	for(auto next : g[curr])
	{
		if(next == prev) continue;

		if(dfsn[curr] > dfsn[next])S.push({curr, next});

		if(dfsn[next] > 0) res = min(res, dfsn[next]);
		else
		{
			int tmp = Dfs(next, curr);
			res = min(res, tmp);

			if(tmp >= dfsn[curr]) {
				vector<pii> currbcc;
				while(!S.empty() && S.top() != pii(curr,next))
				{
					currbcc.push_back(S.top());
					S.pop();
				}
				currbcc.push_back(S.top());
				S.pop();
				bcc.push_back(currbcc);
			}
		}
	}

	//최소도달 가능 dfsn을 리턴해준다
	return res;
}