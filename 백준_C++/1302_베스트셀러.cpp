#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int N, max_size = 0;
map<string, int>dict;
set<string>printlist;
set<string>::iterator iter;
void add_book() {
	int ch, i = 0;
	string a;
	while ((ch = getchar() ) != '\n') {
		a += ch;
	}
	int dup = 0;
	if (dict[a]) {
		dup = dict[a] + 1;
		dict[a] = dup;
	}
	else {
		dict[a] = 1;
		dup = 1;
	}
	if (max_size == dup) {
		printlist.insert(a);
	}
	else if (max_size < dup) {
		printlist.clear();
		max_size = dup;
		printlist.insert(a);
	}
}

int main() {
	scanf("%d ",&N);
	fflush(stdin);
	while (N--)
	{
		add_book();
	}
	cout << *(iter = printlist.begin());
	return 0;
}