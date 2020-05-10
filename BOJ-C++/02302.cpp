#include <iostream>
using namespace std;
typedef long long ll;

ll dp[100] = {1,1,2};

ll func(int n)
{
	if(dp[n] != 0){
		return dp[n];
	}
	else{
		return dp[n] = func(n - 1) + func(n - 2);
	}
}
int main()
{
  int n, m, k;
  ll res = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int tmp = 1;
  for (auto i = 0; i < m; ++i) {
    cin >> k;
    res *= func(k - tmp);
    tmp = k + 1;
  }
  res *= func(n - tmp + 1);
  cout << res;
}