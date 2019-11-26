#include <iostream>
using namespace std;
int M, cnt = 0;
int main()
{
	cin >> M;
	while (M > 0)
	{
		if (M % 2 == 1) {
			cnt++;
		}
		M /= 2;
	}
	printf("%d", cnt);
}