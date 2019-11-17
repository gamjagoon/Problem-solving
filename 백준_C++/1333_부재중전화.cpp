#include <iostream>
using namespace std;
int N, L, D;
int main()
{
	cin >> N >> L >> D;
	int T = 0;
	while (N--) {
		T += L;
		if (T % D == 0)break;
		T++;
		if (T % D == 0)break;
		T++;
		if (T % D == 0)break;
		T++;
		if (T % D == 0)break;
		T++;
		if (T % D == 0)break;
		T++;
	}
	while (T % D != 0)T++;
	printf("%d", T);
	return 0;
}