#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
inline void sw(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
class heap {
private:
	vector<T> arr;
	int getPar(int idx) { return (idx - 1 / 2); }
	int getLeft(int idx) { return 2 * idx + 1; }
	int getRight(int idx){return 2 * idx + 2;}
public:
	void insert(T data);
	T remove();
	void top() {
		printf("%d\n", arr[0]);
	}
};


template <typename T>
void heap<T>::insert(T data) {
	if (arr.size() == 0) {
		arr.push_back(data); return;
	}
	int now = arr.size();
	int par = getPar(now);
	arr.push_back(data);
	//앞에 now > 0 이 없다면 무한루프 
	while (now > 0 && arr[now] > arr[par]) {
		swap(arr[now], arr[par]);
		now = par; par = getPar(now);
	}
}

template<typename T>
T heap<T>::remove()
{
	T ret = arr[0];
	arr[0] = arr.back();
	int left = getLeft(0), right = getRight(0);
	int sel = 0, par = 0;
	while (1) {
		if (left >= arr.size()) break;
		if (right >= arr.size())sel = left;
		else {
			if (arr[left] > arr[right])sel = right;
			else sel = left;
		}
		if (arr[sel] < arr[par]) {
			sw(arr[sel], arr[par]);
			par = sel;
		}
		else break;
		left = getLeft(par);
		right = getRight(par);
	}
	return T();
}

int main() {
	heap<int> a;
	for (int i = 10; i >= 1; --i) {
		a.insert(i);
	}
	for (int i = 1; i < 10; ++i) {
		a.top();
		a.remove();
	}
	return 0;
}
