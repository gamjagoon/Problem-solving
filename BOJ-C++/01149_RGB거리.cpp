#include <iostream>
using namespace std;

int N;
int arr_R[1001] = {
	0,
};
int arr_G[1001]= {
	0,
};
int arr_B[1001]= {
	0,
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int tmp;
	int R, G, B;
	cin >> arr_R[0] >> arr_G[0] >> arr_B[0];
	for (int i = 1; i < N;++i)
	{
		cin >> R >> G >> B;
		if(arr_G[i-1] < arr_B[i-1])
		{
			arr_R[i] = arr_G[i - 1] + R;
		}
		else{
			arr_R[i] = arr_B[i - 1] + R;
		}
		if(arr_G[i-1] < arr_R[i-1])
		{
			arr_B[i] = arr_G[i - 1] + B;
		}
		else{
			arr_B[i] = arr_R[i - 1] + B;
		}
		if(arr_R[i-1] < arr_B[i-1])
		{
			arr_G[i] = arr_R[i - 1] + G;
		}
		else
		{
			arr_G[i] = arr_B[i - 1] + G;
		}
	}
	int min_value = arr_R[N - 1];
	if(min_value > arr_G[N-1])
		min_value = arr_G[N - 1];
	if(min_value > arr_B[N-1])
		min_value = arr_B[N - 1];
	std::cout << min_value;
	return 0;
}