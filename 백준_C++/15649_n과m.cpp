#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool ch[9];
char num[9] = { ' ','1','2','3','4','5','6','7','8'};
int M, N;
string result;
int cnt = 0;
void dfs(int n) {
	if (n > M +1) return;
	if ( cnt== N) {
		for (auto i : result) {
			printf("%c ", i);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= M; ++i) {
		if (ch[i] == false) {
			ch[i] = true;
			result.push_back(num[i]);
			cnt++;
			dfs(n + 1);
			result.pop_back();
			cnt--;
			ch[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &M,&N);
	dfs(1);
	return 0;
}