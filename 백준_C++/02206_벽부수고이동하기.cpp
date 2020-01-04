#include<iostream>
#include <queue>
using namespace std;

typedef pair<pair<int,int>,int>p;
queue<p>q;
int R,C;
int map[1002][1002];
int dist[1002][1002][2];
int dir[4][2] = { {1,0} , {-1, 0}, {0,1}, {0, -1}};
int result = 4000;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>R>>C;
	for (int i = 1; i <= R; ++i) {
		string tmp;
		cin>>tmp;
		for (int j = 0; j < C; ++j) {
			map[i][j+1] = tmp[j] - '0';
			dist[i][j+1][0] = 0;
			dist[i][j+1][1] = 0;
		}
	}
	q.push({{1,1},0});
	dist[1][1][0] = 1;
	while (!q.empty()) {
		int crush = q.front().second;
		int r = q.front().first.first;
		int c = q.front().first.second;
		q.pop();
		if (r == R && c == C) {
			result = result > dist[R][C][crush] ? dist[R][C][crush] : result;
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if(nr <1 || nc < 1 || nr > R|| nc>C)continue;
			//벽이 있고, 벽을 아직 안 뚫었다면
			if (map[nr][nc] == 1 && crush == 0) 
			{
				dist[nr][nc][1] = dist[r][c][0] + 1;
				q.push(make_pair(make_pair(nr,nc),1));
			}
			//벽이 없을떄
			else if(map[nr][nc] == 0 && dist[nr][nc][crush] == 0){
				dist[nr][nc][crush] = dist[r][c][crush] + 1;
				q.push(make_pair(make_pair(nr, nc), crush));
			}
		}
	}
	if (result != 4000){
		cout<<result;
	}
	else {
		cout<<-1;
	}
	return 0;
}