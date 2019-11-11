#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool pushed[32001];
vector <int>Dag[32001];
vector<int>slave(32001);
queue <int>list;
stack<int>result;

/*
ptr 이 가리키는 숫자가 이미 스택에 들어갔거나 1보다 작으면 리턴 return
ptr 보다 뒤에 와야하는 것들이 없다. 그냥 추가
ptr 있으면 검사해서 ptr 보다 우선순위가 있는것보다 더한 우선순위가있다면
재귀로 find 호출
*/
void find(int ptr) {
	if (pushed[ptr] || ptr < 1) {
		return;
	}
	if (Dag[ptr].empty()) {
		result.push(ptr);
		pushed[ptr] = true;
	}
	else {
		int dsize = Dag[ptr].size();
		for (int i = 0; i < dsize; ++i) {
			int tmp = Dag[ptr].back();
			Dag[ptr].pop_back();
			if (pushed[tmp])continue;
			if (Dag[tmp].empty()) {
				result.push(tmp);
				pushed[tmp] = true;
			}
			else {
				find(tmp);
			}
		}
		result.push(ptr);
		pushed[ptr] = true;
	}
	return;
}
//sort 비교용 함수
bool cmp(int a, int b) {
	return a < b;
}


int main()
{
	//입력********************
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int p, s;
	while (M--) {
		cin >> p >> s;
		Dag[p].push_back(s);
		slave[s]++;
	}
	// Dag 의 백터중에 1개 이상인걸 정렬
	for (int i = 1; i <= N; ++i) {
		if (Dag[i].size() > 1) {
			sort(Dag[i].begin(), Dag[i].end(), cmp);
		}
	}
	//정렬해서 스택에 넣는다*****************
	int ptr = N;
	int com = 0;
	while (result.size() < N) {
		for (int i = N; i >= 0; --i) {
			if (slave[i] == com) {
				list.push(i);
			}
		}
		while (!list.empty()) {
			int tmp = list.front();
			list.pop();
			find(tmp);
		}
		com++;
	}
	//스택에서 출력한다*****************
	while (!result.empty())
	{
		printf("%d ", result.top());
		result.pop();
	}
	return 0;
}