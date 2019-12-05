#include <iostream>
#include <iomanip>
#define endl '\n'
using namespace std;
int N, L, R, arr[50][50];
// 0 은 국경선이 있다 1 국경선이 없다
bool line[50][50] = { 0 };
inline int sub(int a, int b) { return a - b > 0 ? a - b : b - a; }

inline void init_line()
{
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			line[i][j] = false;
		}
	}
}


void view_map()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout<< arr[i][j]<<' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void init()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
}
void view_line()
{
	for(int i =0; i<N-1;)
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	init_line();
	view_map();

	cout << "L : " << L << "R : " << R << endl;
}