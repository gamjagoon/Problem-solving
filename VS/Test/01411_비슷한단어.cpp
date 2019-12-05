#include <iostream>
#include <vector>
#include <set>
using namespace std;
multiset<string>mset;
set<string>s;
int result = 0;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string tmp;
	int n;
	int len;
	cin>>n;
	while (n--) {
		cin>>tmp;
		len = tmp.length();
		for (int i = 0; i < len; ++i) {
			if (tmp[i] >= 'a') {
				char a = tmp[i];
				tmp[i] = i+'0';
				for (int j = i + 1; j < len; ++j) {
					if (tmp[j] == a) {
						tmp[j] = i+'0';
					}
				}
			}
		}
		mset.insert(tmp);
		s.insert(tmp);
	}
}

void calc()
{
	for (auto itr = s.begin(); itr != s.end(); itr++) {
		int cnt = mset.count(*itr);
		result += cnt*(cnt-1)/2;
	}
}
int main()
{
	init();
	calc();
	cout<<result;
	return 0;
}