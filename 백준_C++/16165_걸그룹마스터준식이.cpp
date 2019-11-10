#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
string n;
int N, M;
vector<string>G[100];
map<string, int>table;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> n;
		table.insert({ n,i });
		int j; cin >> j;
		string m;
		while (j--) {
			cin >> m;
			G[i].push_back(m);
			table.insert({ m,i });
		}
		sort(G[i].begin(), G[i].end());
		G[i].push_back(n);
	}
	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> n;
		cin >> tmp;
		int g = table[n];
		if (tmp) {//ÆÀ¸í
			cout << G[g][G[g].size() - 1] << '\n';
		}
		else {
			for (int j = 0; j < G[g].size() - 1; ++j) {
				cout << G[g][j] << '\n';
			}
		}
	}
	return 0;
}