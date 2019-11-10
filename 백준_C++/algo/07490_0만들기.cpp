#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, end_index;
char dir[3] = { ' ','+','-' };
int arr[17] = { 1,' ',2,' ',3,' ',4,' ',5,' ',6,' ',7,' ',8,' ',9 };


bool calc() {
	bool ch[17];
	memset(ch, false, sizeof(ch));
	int calclist[10];
	int id_c = 0;
	for (int i = 0; i <= end_index; i++) {
		if (i % 2 == 1 && arr[i] == ' ') {
			ch[i + 1] = true;
			int tmp = calclist[id_c - 1];
			tmp = tmp * 10 + arr[i + 1];
			calclist[id_c - 1] = tmp;
			i++;
		}
		else if (i % 2 == 0 && !ch[i]) {
			calclist[id_c++] = arr[i];
		}
	}
	int index = 1;
	int result = calclist[0];
	//for (int i = 0; i <= end_index; ++i) {
	//	if (i % 2 == 0)printf("%d", arr[i]);
	//	else printf("%c", arr[i]);
	//}
	//printf("\n");
	for (int i = 1; i < id_c; ++i) {
		while (index < end_index && arr[index] == ' ')index += 2;
		if (index >= end_index)break;
		if (arr[index] == '+') {
			result += calclist[i];
			index += 2;
		}
		else {
			result -= calclist[i];
			index += 2;
		}
	}
	if (result == 0) return true;
	else return false;
}


void dfs(int n) {
	if (n > end_index) {
		if (calc())
		{
			for (int i = 0; i <= end_index; ++i) {
				if (i % 2 == 0)printf("%d", arr[i]);
				else printf("%c", arr[i]);
			}
			printf("\n");
		}
		return;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			int ch = dir[i];
			arr[n] = ch;
			dfs(n + 2);
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		end_index = tmp * 2 - 2;
		dfs(1);
		printf("\n");
	}
	return 0;
}