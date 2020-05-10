#include <iostream>
#include <map>
#include <set>
using namespace std;
int N, max_size = 0;
map<string, int>dict;
set<string>printlist;
void add_book() {
	string a;
	cin>>a;
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
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>N;
	while (N--)
	{
		add_book();
	}
	cout << *printlist.begin();
	return 0;
}