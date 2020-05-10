#include <iostream>
using namespace std;

int wines[10002][3] = {
	{
		0,
	},
};
int N, tmp;

void solve_under_2(int N)
{
	int res = 0;
	for (int i = 0; i < N;++i)
	{
		cin>>tmp;
		res += tmp;
	}
	cout << res;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	if(N <= 2)
	{
		solve_under_2(N);
		return 0;
	}
	else
	{
		cin >> tmp;
		wines[1][0] = 0;
		wines[1][1] = tmp;
		for (int i = 2; i <= N;++i)
		{
			cin >> tmp;
			wines[i][1] = wines[i - 1][0] + tmp;
			if(wines[i-1][0] > wines[i-1][1]){
				if(wines[i-1][0] > wines[i-1][2])
					wines[i][0] = wines[i - 1][0];
				else
					wines[i][0] = wines[i-1][2];
			}
			else{
				if(wines[i-1][1] > wines[i-1][2])
					wines[i][0] = wines[i - 1][1];
				else
					wines[i][0] = wines[i-1][2];
			}
			wines[i][2] = wines[i-1][1] + tmp;
		}
		int max_value = wines[N][0];
		if(max_value < wines[N][1])
			max_value = wines[N][1];
		if(max_value < wines[N][2])
			max_value = wines[N][2];
		cout << max_value;
	}
	return 0;
}