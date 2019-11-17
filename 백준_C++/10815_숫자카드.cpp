#include <iostream>
#include <set>
using namespace std;
int N, M;
set<int>a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		a.insert(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> tmp;
		cout << a.count(tmp) << ' ';
	}
	return 0;
}