#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*전역 변수*/
int R, C, T, ur, uc, dr, dc, result = 0;
int arr[50][50];
vector<pair<int, int> > M;
queue<pair<int, int> > X;

//동 서 북 남;
int dir_r[4] = { 0,0,-1,1 };
int dir_c[4] = { 1,-1,0,0 };

void view_map() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void add_X() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] == -1 || arr[i][j] == 0)continue;
			else {
				X.push(make_pair(i, j));
			}
		}
	}
}

void wacsan()
{
	int narr[50][50] = { 0 };
	while(!X.empty()){
		int r = X.front().first;
		int c = X.front().second;
		X.pop();
		int n = 0; int v = arr[r][c] / 5;
		for(int j = 0 ; j < 4;++j){
			int nr = r + dir_r[j];
			int nc = c + dir_c[j];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || arr[nr][nc] == -1)
				continue;
			n++;
			narr[nr][nc] += v;
		}
		arr[r][c] -= v * n;
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			arr[i][j] += narr[i][j];
		}
	}
}

void rotate_arr(int r, int c)
{
	for (int i = r - 1; i > 0; --i) arr[i][0] = arr[i - 1][0];
	for (int i = 0; i < C - 1; ++i) arr[0][i] = arr[0][i + 1];
	for (int i = 0; i < r ; ++i)arr[i][C - 1] = arr[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--)arr[r][i] = arr[r][i - 1];

	for (int i = r + 2; i < R-1; ++i) arr[i][0] = arr[i + 1][0];
	for (int i = 0; i < C - 1; ++i) arr[R-1][i] = arr[R-1][i + 1];
	for (int i = R-1; i > r+1; --i)arr[i][C - 1] = arr[i - 1][C - 1];
	for (int i = C - 1; i > 1; --i)arr[r+1][i] = arr[r+1][i - 1];
	arr[r][1] = 0;
	arr[r + 1][1] = 0;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tmp;
	cin >> R >> C >> T;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> tmp;
			if (tmp == 0)
			{
				arr[i][j] = tmp;
			}
			else if (tmp != -1) {
				arr[i][j] = tmp;
				X.push(make_pair(i, j));
			}
			else 
			{
				arr[i][j] = tmp;
				M.push_back(make_pair(i, j));
			}
		}
	}
	ur = M[0].first; uc = M[0].second;
	while (T--) {
		wacsan();
		rotate_arr(ur, uc);
		add_X();
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] != -1) {
				result += arr[i][j];
			}
		}
	}
	cout << result;
	return 0;
}