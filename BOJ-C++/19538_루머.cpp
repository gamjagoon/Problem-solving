#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int res[200001];
int ru[200001];
vector <int>g[200001];
queue<int>q;
queue<int>up;
int N;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N;
	int tmp;
	for(int i = 1; i <= N; i++){
		res[i] = -1;
		while(1){
			cin>>tmp;
			if(tmp){
				g[i].push_back(tmp);
				g[tmp].push_back(i);
			}else {
				break;
			}
		}
	}
	int M;cin>>M;
	for(int i = 0; i < M;i++){
		cin>>tmp;
		res[tmp] = 0;
		q.push(tmp);
		for(auto j : g[tmp]){
			ru[j]++;
		}
	}

	int t = 1;
	int cur, sz, cnt,qsz;
	while(!q.empty()){
		qsz = q.size();
		while(qsz--){
			cur = q.front();
			q.pop();
			for(auto k : g[cur]){
				if(res[k] >= 0)continue;
				sz = g[k].size();
				if(sz % 2)sz = sz / 2 + 1;
				else sz /= 2;
				cnt = ru[k];
				if(cnt >= sz){
					res[k] = t;
					up.push(k);
					q.push(k);
				}
			}
		}
		while(!up.empty()){
			cur = up.front();up.pop();
			for(auto j : g[cur]){
				ru[j]++;
			}
		}
		t++;
	}
	for(int i = 1; i <= N;i++){
		cout<<res[i]<<" ";
	}
}
