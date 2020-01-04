#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,int>m;
vector<string>res;
string mins[] = { "a","b","k","d","e","g","h","i","l","m","n","ng","o","p","r" ,"s" ,"t" ,"u" ,"w", "y"};
int N;
int main()
{
	for (int i = 0; i < 20; ++i) {
		m.insert(make_pair(mins[i],i));
	}
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>N;
	while (N--)
	{
		string tmp;
		cin>>tmp;
		int len = tmp.length();
		string memo = "";
		for (int i = 0; i < len; ++i) {
			string sl = tmp.substr(i,1);
			if (tmp[i] != 'n') {
				memo += m[sl];
			}
			else if (i + 1 < len && tmp[i + 1] == 'g') {
				sl = tmp.substr(i,2);
				memo+= m[sl];
				i++;
			}
			else {
				memo+=m[sl];
			}
		}
		res.push_back(memo);
	}
	sort(res.begin(),res.end());
	for (auto i : res) {
		for (auto j : i)
		{
			cout<<mins[j];
		}
		cout<<'\n';
	}
	return 0;
}