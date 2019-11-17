#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
int R, C, result = 64;
char map[50][50];
char B[8] = { 'B','W','B','W' ,'B','W' ,'B','W'};
char W[8] = { 'W','B','W' ,'B','W' ,'B','W','B'};
void view() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

inline void compare(char arr[], int r, int c, int& tmp,int i) {
	for (int j = 0; j < 8; ++j) {
		if (map[r + i][c + j] != arr[j]) {
			tmp++;
		}
	}
}

void calc(int r, int c)
{
	int tmp = 0;
	for(int i = 0; i < 8; ++i) {
		if (i % 2 == 1)
			compare(B, r, c, tmp,i);
		else
			compare(W, r, c, tmp,i);
	}
	result = result < tmp ? result : tmp;
	tmp = 0;
	for (int i = 0; i < 8; ++i) {
		if (i % 2 == 1)
			compare(W, r, c, tmp, i);
		else
			compare(B, r, c, tmp, i);
	}
	result = result < tmp ? result : tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; ++j) {
			map[i][j] = tmp[j];
		}
	}
	for (int i = 0; i < R - 7; ++i) {
		for (int j = 0; j < C - 7; ++j) {
			calc(i, j);
			if (result == 0) {
				printf("0");
				return 0;
			}
		}
	}
	cout << result;
	return 0;
}