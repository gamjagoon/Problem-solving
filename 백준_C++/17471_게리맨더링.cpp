#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int city[11];
int N, K, result;
bool ch[11];
set<pair<int,int>>B;
vector<int>red(9);
vector<int>blue(9);


int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		city[i] = tmp;
	}
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &K);
		int tg;
		for (int j = 0; j < K; ++j) {
			scanf("%d", &tg);
			B.insert(make_pair(i, tg));
		}
	}
	
	return 0;
}