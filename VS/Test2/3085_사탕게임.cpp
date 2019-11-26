#include <iostream>
using namespace std;

char map[50][50];
int N, result = 0;

void max_char(int r,int c)
{
	char key = map[r][0];
	int cnt = 1;
	for (int i = 1; i < N; ++i)
	{
		if (map[r][i] == key)
		{
			cnt++;
		}
		else {
			result = cnt > result ? cnt : result;
			cnt = 1;
			key = map[r][i];
		}
	}
	result = cnt > result ? cnt : result;
	key = map[0][c];
	cnt = 1;
	for (int i = 1; i < N; ++i)
	{
		if (map[i][c] == key)
		{
			cnt++;
		}
		else {
			result = cnt > result ? cnt : result;
			cnt = 1;
			key = map[i][c];
		}
	}
	result = cnt > result ? cnt : result;
}
inline void _swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
	return ;
}
void calc()
{
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N-1; ++j) {
			_swap(map[i][j], map[i][j + 1]);
			max_char(i, j);
			max_char(i, j + 1);
			_swap(map[i][j], map[i][j + 1]);
			_swap(map[i][j], map[i+1][j]);
			max_char(i+1, j);
			max_char(i, j);
			_swap(map[i+1][j], map[i][j]);
		}
	}
	for (int i = 0; i < N-1; ++i)
	{
		_swap(map[i][N - 1], map[i + 1][N - 1]);
		max_char(i + 1, N - 1);
		max_char(i, N - 1);
		_swap(map[i][N - 1], map[i + 1][N - 1]);
	}
	for (int j = 0; j < N - 1; ++j)
	{
		_swap(map[N-1][j], map[N-1][j+1]);
		max_char(N-1, j);
		max_char(N-1, j+1);
		_swap(map[N-1][j], map[N-1][j+1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)for (int j = 0; j < N; ++j)cin >> map[i][j];
	calc();
	printf("%d", result);
	return 0;
}