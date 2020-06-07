#include <iostream>

using namespace std;

int t_case, R;
string S;

void solve()
{
	cin >> R >> S;
	for(auto i : S) //  "abcd"
	{
		int t = R;
		while(t--)
		{
			cout << i;
		}
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> t_case;
	while(t_case--)
	{
		solve();
	}
	return 0;
}