#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> g[32010];
vector<int> indegree(32010);
priority_queue<int> pq;

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
		indegree[b]++;
	}
	for(int i=1; i<=n; i++) if(!indegree[i]) pq.push(-i);
	while(!pq.empty()){
		int poped = -pq.top(); pq.pop();
		printf("%d ", poped);
		for(int i=0; i<g[poped].size(); i++){
			int nxt = g[poped][i];
			indegree[nxt]--;
			if(!indegree[nxt]) pq.push(-nxt);
		}
	}
}