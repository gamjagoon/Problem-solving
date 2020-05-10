#include <iostream>
using namespace std;

long N, M, result = 0;
long arr[1000000];
bool calc(long H)
{
	long sum = 0;
	for (int i = 0; i < N;++i)
	{
		if(arr[i] - H > 0)
		{
			sum += (arr[i] - H);
		}
	}
	if(sum >= M)
		return true;
	else
		return false;
}

int find(long s,long e)
{
	long m = (s+e)/2;
	if(s > e)
		return e;
	else if( calc(m))
	{
		return find(m + 1, e);
	}
	else{
		return find(s, m-1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int max = 0;
	for (int i = 0; i < N;++i)
	{
		cin >> arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	cout << find(0, max);
	return 0;
}