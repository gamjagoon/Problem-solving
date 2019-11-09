#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
bool city[11][11];
int N,peaple[11],result = 2000;
vector<int>team[2];

void bfs()
{
	bool team_status[2][11];
	bool visited[2][11];
	memset(team_status,false,sizeof(team_status));
	memset(visited,false,sizeof(visited));
	for(int i = 0 ; i < 2; ++i){
		for(int j = 0; j < team[i].size();++j){
			team_status[i][team[i][j]] = true;
		}
	}
	int cnt_pepl[2];
	cnt_pepl[0] = 0;
	cnt_pepl[1] = 0;
	for(int i = 0 ; i < 2;++i)
	{
		if(team[i].size() == 1)
		{
			cnt_pepl[i] = peaple[team[i][0]];
			continue;
		}
		queue<int>q;
		q.push(team[i][0]);
		visited[i][team[i][0]]= true;
		while(!q.empty())
		{
			int now = q.front();
			q.pop();
			for(int j = 1; j <= N;++j)
			{
				if(city[now][j] && team_status[i][j] && !visited[i][j])
				{
					visited[i][j] = true;
					q.push(j);
				}
			}
		}
		for(int j = 0;j < team[i].size();++j)
		{
			if(!visited[i][team[i][j]])return;
			cnt_pepl[i]+= peaple[team[i][j]];
		}
	}
	int res = cnt_pepl[0]-cnt_pepl[1];
	if(res < 0)res*=-1;
	result = res < result ? res: result;
	return;
}

void dfs(int depth)
{
	if(depth == N+1){
		if(team[0].size() > 0 && team[1].size() > 0)
			bfs();
		return;
	}
	for(int i = 0 ; i < 2;++i)
	{
		team[i].push_back(depth);
		dfs(depth+1);
		team[i].pop_back();
	}
}


int main()
{
	scanf("%d",&N);
	for(int i=1; i <= N;++i)
	{
		scanf("%d",&peaple[i]);
	}
	for(int i = 1 ; i <= N;++i)
	{
		int K;scanf("%d",&K);
		int tg;
		for(int j = 0;j < K;++j)
		{
			scanf("%d",&tg);
			city[i][tg] = true;
			city[tg][i] = true;
		}
	}
	dfs(1);
	if(result == 2000)printf("-1");
	else printf("%d",result);
	return 0;
}