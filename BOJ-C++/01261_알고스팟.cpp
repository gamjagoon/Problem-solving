#include <iostream>
#include <queue>

using namespace std;

int N, M;//c r
int arr[100][100];
int ch[100][100] = { 0 };
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
deque<pair<int, int> >dq;

void init() {
	cin >> N >> M;
	string a;
	for (int i = 0; i < M; ++i) {
		cin >> a;
		for (int j = 0; j < N; ++j) {
			arr[i][j] = a[j]-'0';
		}
	}
}
void view_map()
{
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void calc()
{
	ch[0][0] = 1;
	dq.push_back(make_pair(0, 0));
	while (!dq.empty())
	{
		int r = dq.front().first;
		int c = dq.front().second;
		dq.pop_front();
		for (int s = 0; s < 4; ++s) {
			int nr = r + dir[s][0];
			int nc = c + dir[s][1];
			if (nr < 0 || nc < 0 || nr >= M || nc >= N)continue;
			if (arr[nr][nc] == 1 && ch[nr][nc] == 0) {//벽을 부수고 나간다
				dq.push_back(make_pair(nr, nc));
				ch[nr][nc] = ch[r][c] + 1;
			}
			else if(ch[nr][nc] == 0){
				dq.push_front(make_pair(nr, nc));
				ch[nr][nc] = ch[r][c];
			}
		}
	}
}

int main()
{
	init();
	calc();
	printf("%d", ch[M - 1][N - 1] -1 );
	return 0;
}