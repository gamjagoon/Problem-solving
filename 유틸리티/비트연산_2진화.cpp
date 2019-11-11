#include <stdio.h>
#include <stack>
int main() {
	int m;
	int i = 1;
	while (1)
	{
		scanf("%u", &m);
		unsigned int N = m;
		if (N == 0) {
			printf("0\n");
			continue;
		}
		//if( N > 0)
		//{
			std::stack<bool>st;
			while (N != 0)
			{
				st.push(N & i);
				N >>= 1;
			}
			while (!st.empty()) {
				printf("%d", st.top());
				st.pop();
			}
			printf("\n");
		//}
		//else {
		//	std::stack<bool>st;
		//	while (N != 1)
		//	{
		//		st.push(N & i);
		//		N >>= 1;
		//		printf("%d\n", N);
		//	}
		//	while (!st.empty()) {
		//		printf("%d", st.top());
		//		st.pop();
		//	}
		//	printf("\n");
		//}
	}
	return 0;
}
