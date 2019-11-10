#include <stdio.h>

int numbers[1000000];
int N;

void quickSort(int left, int right) {
	int i = left, j = right;
	int pivot = numbers[(left + right) / 2];
	int temp;
	do {
		while (numbers[i] < pivot) i++;
		while (numbers[j] > pivot)j--;
		if (i <= j) {
			temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(left, j);
	if (i < right)quickSort(i, right);
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &numbers[i]);
	}
	quickSort(0, N-1);
	for (int i = 0; i < N; ++i) {
		printf("%d\n", numbers[i]);
	}
	return 0;
}