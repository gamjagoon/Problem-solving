#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	if (num == 1)
	{
		cout << "*" << '\n';
		return 0;
	}
	
	for (int i = 1; i < num; i++)
	{
		cout << " ";
	}
	cout << "*" << '\n';
	for (int i = 1; i < num; i++)
	{
		
		for (int t = 1; t < (num - i) ; t++)
			cout << " ";
		{
			cout << "*";
			for (int j = 1; j <= 2 * i - 1; j++)
			{
				cout << " ";
			}
		cout << "*" << '\n'; 
		}
	
	}
}