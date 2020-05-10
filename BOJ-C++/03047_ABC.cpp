#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
string tmp;
vector<int> bufs;

int main()
{
	bufs.resize(3);
	for (int i = 0; i < 3;++i)
	{
		cin >> bufs[i];
	}
	cin >> tmp;

	sort(bufs.begin(),bufs.end());
	for (int i = 0; i < 3;++i)
	{
		cout << bufs[tmp[i] - 'A']<<' ';
	}
	return 0;
}