#include <iostream>
#include <vector>
#define MAX 1e9+7

using namespace std;
int n, m;
int map[101][101];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			map[i][j] = MAX;
		}
	}
	for (int i = 1; i <= n; ++i)map[i][i] = 0;
	int st, ed, ct;
	for (int i = 0; i < m; ++i) {
		cin >> st >> ed >> ct;
		if (map[st][ed] < ct)continue;
		map[st][ed] = ct;
	}
}
void floid()
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}
void view_map()
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] == MAX || map[i][j] == 0)printf("0 ");
			else printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	init();
	floid();
	view_map();
	return 0;
}