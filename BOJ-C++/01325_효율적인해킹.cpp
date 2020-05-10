#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
#define INF 1000000009
#define endl '\n'

using namespace std;

//Global

array<vector<int>, 10001>g;
int N,M;
array<bool, 10001>ch;
vector<pair<int,int>>node;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N>>M;
	while(M--){
		int e,s;
		cin>>e>>s;
		g[s].push_back(e);
	}
	node.resize(N);
	for(int i = 0; i < N;i++){
		ch.fill(false);
		queue<int>q;
		int cnt = 0;
		q.push(i+1);
		cnt++;
		ch[i+1] = true;
		while(!q.empty()){
			int curr = q.front();q.pop();
			for(auto to : g[curr]){
				if(!ch[to]){
					ch[to] = true;
					cnt++;
					q.push(to);
				}
			}
		}
		node[i].first = i+1;node[i].second = cnt;
	}
	sort(node.begin(),node.end(),[](pair<int,int>&a,pair<int,int>&b){if(a.second == b.second)return a.first < b.first;return a.second > b.second;});
	for(int i = 0; i < N;i++){
		if(node[0].second == node[i].second){
			cout<<node[i].first<<' ';
		}else break;
	}
}
