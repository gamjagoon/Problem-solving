#include <cstdio>
#include <vector>
using namespace std;
char arr[51][51];
int R, C, r, c, x, y;
vector<pair<int, int>>W;
void init();
void view_map();
void bfs()
{

}
int main()
{
	init();
	view_map();
	bfs();

	return 0;
}

void init()
{
	scanf("%d %d ", &R, &C);
	W.reserve(2498);
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			char ch;
			scanf("%c", &ch);
			if (ch == 'D') {
				r = i;
				c = j;
				arr[i][j] = ch;
			}
			else if (ch == '*') {
				W.push_back(make_pair(i, j));
				arr[i][j] = 'X';
			}
			else if (ch == 'X') {
				arr[i][j] = ch;
			}
			else if (ch == 'S') {
				y = i;
				x = j;
				arr[i][j] = 'S';
			}
			else {
				arr[i][j] = '.';
			}
		}
		getchar();
	}
}

void view_map()
{
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	return;
}