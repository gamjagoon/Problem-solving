#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N)
	{
		for (int i = 0; i < N; ++i) {
			cout << '*';
		}
		if(N!= 1)cout << '\n'; N--;
	}
	return 0;
}