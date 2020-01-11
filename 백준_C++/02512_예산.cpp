#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
int N, result = 0 , s = 100000, e = 0, Max;
void find(int start, int end) {
	if (start > end)return;
	int key = start + (end - start) / 2;
	int res = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (key <= arr[i]) {
			res += key;
		}
		else {
			res += arr[i];
		}
	}
	if (res == Max) {
		result = key;
		return;
	}
	else if (res < Max) {
		result = key > result ? key : result;
		find(key+1 , end);
	}
	else {
		find(start, key-1);
	}
}

int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		s = min(s, tmp);
		e = max(e, tmp);
		arr.push_back(tmp);
	}
	cin >> Max;
	find(0, e);
	cout << result;
	return 0;
}