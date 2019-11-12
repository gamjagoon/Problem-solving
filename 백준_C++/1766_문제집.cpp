#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int indegree[32001];
vector<int> D[32001];
// vector<int>ordered_list;
priority_queue<int>pq;
// bool com(int a,int b){
// 	return a > b;
// }
int main()
{
	//입력 받기 ***********************
	int M;
	scanf("%d %d",&N,&M);
	int p,s;
	while(M--){
		scanf("%d %d",&p,&s);
		indegree[s]++;
		D[p].push_back(s);
	}
	/*
	입력 받은걸로 위상정렬을 수행
	일단 인디그리가 0인거부터 q 에 넣는다
	*/
	// for(int i = 1; i <= N;++i){
	// 	sort(D[i].begin(),D[i].end());
	// }
	for(int i = 1; i <= N;++i){
		if(!indegree[i]){
			pq.push(-i);
		}
	}
	while(!pq.empty()){
		int here = -pq.top();
		printf("%d ",here);
		pq.pop();
		for(int i = 0; i < D[here].size();++i){
			int tmp = D[here][i];
			indegree[tmp]--;
			if(!indegree[tmp])pq.push(-tmp);
		}
	}
}