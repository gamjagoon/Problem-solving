#include <iostream>
using namespace std;

int J, k, n;

char *buf[] =
	{
		"baby", "sukhwan", "tururu", "turu",
		"very", "cute", "tururu", "turu",
		"in", "bed", "tururu", "turu",
		"baby", "sukhwan"};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	n--;
	J = n / 14;
	k = n % 14;
	if(k == 2 ||k == 3 ||k == 6 ||k == 7 ||k == 10 ||k == 11)
	{
		J += 1;
		if(k%2 == 0)
		{
			J += 1;
		}
		if(J >= 5)
		{
			cout << "tu+ru*" << J;
		}
		else
		{
			cout << "tu";
			for (int i = 0; i < J;++i)
			{
				cout << "ru";
			}
		}
	}
	else
	{
		cout << buf[k];
	}
	return 0;
}