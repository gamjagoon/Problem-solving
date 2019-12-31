#include <stdio.h>

 int heap_count = 0, N;
 int heap[100001]; // root = 1

inline void swap( int* a,  int* b) {
	 int tmp = *a;
	*a = *b;
	*b = tmp;
}

//힙의 가장 끝에 데이터 추가
void my_push( int data) {
	heap[++heap_count] = data;
	 int child = heap_count;
	 int parent = child / 2;
	/*parent < child  을떄 스왑 == max heap
	   child < parent 을때 스왑 == min heap*/
	while (child > 1 && heap[parent] > heap[child]) { 
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

 int my_pop() {
	 int result = heap[1];
	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	  int parent = 1;
	 int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] < heap[child + 1]) ? child : child + 1;
	}
	while (child <= heap_count && heap[parent] > heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] < heap[child + 1]) ? child : child + 1;
		}
	}
	return result;
}

int main(void) {
	scanf("%d", &N);
	 int tmp;
	while (N--) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			if (heap_count == 0)printf("0\n");
			else {
				printf("%d\n",my_pop());
			}
		}
		else {
			my_push(tmp);
		}
	}
	return 0;
}