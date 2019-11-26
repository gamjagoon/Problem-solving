#include <iostream>
using namespace std;
int N, M, L;
int cnt[1001];
int shot_cnt = 0;
int shot(int n)
{
	int tmp_M = cnt[n];
	if (tmp_M % 2 == 0) 
	{ 
		n -= L;
		if (n <= 0) {
			n = N + n;
		}
		cnt[n]+=1;
		return n;
	}
	else
	{
		n += L;
		if (n > N) {
			n -= N;
		}
		cnt[n]+=1;
		return n;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> L;
	int t = N;
	while (t--)cnt[t] = 0;
	cnt[1] = 1;
	int s = 1;
	while (cnt[s] < M) {
		s = shot(s);
		shot_cnt++;
	}
	cout << shot_cnt;
	return 0;
}