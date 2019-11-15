#include <iostream>
#include <cstdio>
#include <random>
constexpr auto MAX = 200;
using namespace std;
void quicksort(int *a,int l, int r);
void merge(int* a, int p, int q, int r);
void mergeSort(int* a, int p, int r);


random_device rd;
uniform_int_distribution<int> range(-100, 100);
int arr[MAX];


inline void sw(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	for (int i = 0; i < MAX; ++i) {
		arr[i] = range(rd);
	}
	for (auto i : arr) {
		printf("%d ", i);
	}
	printf("\n");
	mergeSort(arr, 0, MAX - 1);
	//quicksort(arr, 0, MAX - 1);
	for (auto i : arr) {
		printf("%d ", i);
	}
	return 0;
}

void quicksort(int* arr, int left, int right) {
	int i = left, j = right;
	int pivot = arr[left + (right - left) / 2];
	do {
		while (arr[i] < pivot)i++;
		while (arr[j] > pivot)j--;
		if (i <= j) {
			sw(arr[i], arr[j]);
			i++; j--;
		}
	} while (i <= j);
	if (j > left)quicksort(arr, left, j);
	if (i < right)quicksort(arr, i, right);
}

void merge(int* a, int p, int q, int r)
{
	int i = p, j = q + 1, k = p;
	int tmp[MAX] = { 0 };
	while (i <= q || j <= r) {
		if (i > q) tmp[k++] = arr[j++];
		else if (j > r)tmp[k++] = arr[i++];
		else if (arr[i] <= arr[j])tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	for (int i = p; i <= r; ++i)arr[i] = tmp[i];
}

void mergeSort(int* a, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	}
}
