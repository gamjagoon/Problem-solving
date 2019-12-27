#include <iostream>
#include <vector>
using namespace std;
int N;
string strs[101];

bool check_group(string &str)
{
	bool prev_checked_char[26] = {false};
	int s = str.size();
	int p = str[0];
	int ch;
	for (int i = 1; i < s;++i)
	{
		ch = str[i];
		if(p != ch && prev_checked_char[ch-'a'])
		{
			return false;
		}
		else if(p != ch)
		{
			prev_checked_char[p - 'a'] = true;
			p = ch;
		}
	}
	return true;
}

int solve()
{
	int sum = 0;
	for (int i = 0; i < N;++i)
	{
		if(check_group(strs[i]))
		{
			sum++;
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> strs[i];
	}
	cout << solve();
	return 0;
}