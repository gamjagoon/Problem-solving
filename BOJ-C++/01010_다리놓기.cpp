#include <iostream>
using namespace std;
int test_case, A, B;

#include <iostream>

#define MAX_SIZE 1000
int arr[40][40];
int func(int n, int r) {
	// nCr = (n-1)C(r-1) + (n-1)C(r)
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= r; j++) {

			if (i == j || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	return arr[n][r];

}

int main()
{
	cin >> test_case;
	for (int i = 0; i < test_case; ++i)
	{
		cin >> A >> B;
		printf("%d\n",func(B, A));
	}
	return 0;
}