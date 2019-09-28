#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int r, c, v;
};

#define pi pair<int, int>
#define N 16
#define M 16
#define K 3

int map[N][M];
int arr[M];
vector<pi> killPos;
int n, m, d, sum, MAX = 0;

int dr[3] = { 0, -1, 0 };
int dc[3] = { -1, 0, 1 };

int check(int r, int c) { // 각각의 궁수가 죽일 적의 위치 찾기
    
    /////////////////////////////////////////////////////r을 n부터 시작했으므로 몇가지 예외처리해줬습니다.
	if(map[r-1][c]==2) return 0;
	if(map[r-1][c]==1){
		killPos.push_back({ r-1,c });
		map[r-1][c] = 2;
		return 1;
	}
    /////////////////////////////////////////////////////
    
	bool vst[N][M] = { false, };
	queue<Pos> q;
    
    ///////////////////////////////////////// r을 r-1로 바꿈
	q.push({ r-1, c, 1 });
	vst[r-1][c] = true;
    ////////////////////////////////////////

	while (!q.empty()) {
		Pos top = q.front();
		q.pop();

		int nv = top.v + 1;
		if (nv > d) continue; //d를 벗어나는 곳은 탐색하지 않음

		for (int i = 0; i < 3; i++) {
			int nr = top.r + dr[i];
			int nc = top.c + dc[i];
			
			if (nr < 0 || nc < 0 || nc >= m) continue;
			if (vst[nr][nc]) continue;

			if (map[nr][nc] == 2) return 0; //앞의 궁수가 이미 죽인 적과 중복되므로 0명 리턴
			
			else if (map[nr][nc] == 1) {
				map[nr][nc] = 2;
				killPos.push_back({ nr, nc });
				return 1; //죽일 적이 1명 있으므로 1명 리턴
			}

			else {
				vst[nr][nc] = true;
				q.push({ nr, nc, nv });
			}
		}
	}

	return 0; //궁수가 죽일 수 있는 범위 안에 적이 없으면 0명 리턴
}

void run() {
    /////////////////////////////////// for문의 r을 n에서부터 시작했습니다.
	for (int r = n; r > 0; r--) {
    ///////////////////////////////////
		killPos.clear();

		for (int i = 0; i < 3; i++) {

			sum += check(r, arr[i]); //리턴 된 값을 더해줌
		}

		for (int i = 0; i < killPos.size(); i++)  //2로 바꿔놓은 죽은 적들을 한번에 0으로 처리하기
			map[killPos[i].first][killPos[i].second] = 0;
	}
}

void dfs(int cnt, int k) { //궁수 조합
	if (cnt == 3) {
		int tempMap[N][M] = { 0, }; 
		for (int i = 0; i < n; i++) //배열 백업
			for (int j = 0; j < m; j++) 
				tempMap[i][j] = map[i][j];

		sum = 0;
		run();
		if (MAX < sum) MAX = sum;

		for (int i = 0; i < n; i++) //다시 원래대로
			for (int j = 0; j < m; j++)
				map[i][j] = tempMap[i][j];

		return;
	}

	for (int i = k; i <= m - (K - cnt); i++) {
		arr[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d\n", MAX);
	
	return 0;
}