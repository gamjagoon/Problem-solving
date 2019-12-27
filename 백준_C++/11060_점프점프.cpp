#include <iostream>
#include <vector>
using namespace std;

int N;
int v[1001];
int time[1001];

int main()
{
	cin >> N;
	for (int i = 0; i < N;++i)
	{
		time[i] = 0;
		v[i] = 0;
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		
		for (int j = 1; j <= v[i]; ++j)
		{
			if(i + j >= N )
				break;
			if(time[i] == 0 && i != 0)
				continue;
			if (time[i + j] == 0)
			{
				time[i + j] = time[i] + 1;
			}
			else if (time[i + j] > time[i] + 1)
			{
				time[i + j] = time[i] + 1;
			}
		}
	}
	if(N== 1)
		cout << 0;
	else if(time[N-1] == 0)
		cout << -1;
	else
		cout << time[N - 1];
}