#include <iostream>
#include <set>
using namespace std;
bool ch['Z'+1]['Z'+1] = {false};
bool is_sup(string& a)
{
	int len = a.length();
	if(len == 1 || len == 2)return true;
	int n = len - 1;
	while (n > 0)
	{
		for (int i = 'A'; i <= 'Z'; ++i)for (int j = 'A'; j <= 'Z'; ++j)ch[i][j] = false;
		for (int i = 0; i < len; i++) 
		{
			if(i+n >= len)break;
			else {
				if (!ch[a[i]][a[i + n]]) {
					ch[a[i]][a[i+n]] = true;
				}
				else {
					return false;
				}
			}
		}
		n--;
	}
	return true;
}

int main()
{
	string a;
	while (1)
	{
		cin>>a;
		if(a == "*")break;
		else {
			if (is_sup(a)) {
				cout<<a<<" is surprising."<<'\n';
			}
			else {
				cout << a << " is NOT surprising."<<'\n';
			}
		}
	}
	return 0;
}