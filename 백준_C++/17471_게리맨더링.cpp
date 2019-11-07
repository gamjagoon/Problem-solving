#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int city[11];//인구수
int N, K, result = 1000;
vector <int>B[11];//도시에 간선정보
bool team[2][11];
int size_team[2] = { 0,0 };
int score = 0, cnt = 1;
int parent[11];


int find_parent(int i)
{
	if (parent[i] == i)return i;
	else {
		return find_parent(parent[i]);
	}
}

void find_union()
{
	for (int i = 1; i <= N; ++i) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; ++i) {
		for(int j = 0;j < B[i].size();++j)
		{
			if (parent[i] < find_parent(B[i][j]) ){
				parent[B[i][j]] = parent[i];
			}
		}
	}
	int ori = parent[1];
	int prev = parent[1];
	for (int i = 2; i <= N; ++i) {
		ori = parent[i];
		if (ori != prev) {
			cnt++;
			prev = ori;
		}
	}
}

bool find_loop(int i) {
	bool not_loop = true;
	for (int j = 1; j <= N; ++j) {
		if (team[i][j] == true) {

			if (i == 0)score += city[j];
			else score -= city[j];

			not_loop = true;
			for (int k = 0; k < B[j].size(); ++k) {
				if (team[i][B[j][k]] == true)
				{
					not_loop = false;
					break;
				}
			}
			if (not_loop)return false;
		}
	}
	return true;
}

void bfs()
{
	//열결 되어있으면 각자의 도시 인원 추가
	//연결이 안되었다면 return
	//최종 결과를 return
	score = 0;
	if (size_team[0] > size_team[1]) {
		if (!find_loop(0))return;
		if (!find_loop(1))return;
	}
	else {
		if (!find_loop(1))return;
		if (!find_loop(0))return;
	}
	if (score < 0) score *= -1;
	result = result < score ? result : score;
	return;
}

void solve(int n) {
	if (n == N+1) {
		if (size_team[0] > 0 && size_team[1] > 0) {
			//view_team();
			bfs();
		}
		return;
	}
	for (int i = 0; i < 2;++i) {
		team[i][n] = true;
		size_team[i]++;
		solve(n + 1);
		size_team[i]--;
		team[i][n]=false;
	}
}


int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		city[i] = tmp;
	}
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &K);
		B[i].reserve(K);
		int tg;
		for (int j = 0; j < K; ++j) {
			scanf("%d", &tg);
			B[i].push_back(tg);
			B[tg].push_back(i);
		}
	}
	find_union();
	if (cnt > 2)
	{
		printf("-1");
		return 0;
	}
	solve(1);
	if (result == 1000)printf("-1");
	else printf("%d", result);
	return 0;
}