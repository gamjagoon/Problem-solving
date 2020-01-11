#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//data structure
string T,P;
vector<int>table;
int Tlen = 0;
int Plen = 0;

//result data
int cnt = 0;
queue<int>re;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin , T);
	getline(cin, P);
	Tlen = T.length();
	Plen = P.length();
}

vector <int>make_table(int len,string&pattern)
{
	//패던의 사이즈만큼 백터 초기화
	vector<int>table(Plen,0);
	int j = 0;
	for (int i = 1; i < len; ++i) {
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string& parent, string& pattern,int parentSize,int patternSize)
{
	int j = 0;
	for (int i = 0; i < parentSize; ++i)
	{
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j-1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				cnt++;
				re.push(i-Plen+2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main()
{
	init();
	table = make_table(Plen,P);
	KMP(T,P,Tlen,Plen);
	cout<<cnt<<'\n';
	while (!re.empty())
	{
		cout<<re.front()<<'\n';
		re.pop();
	}
	return 0;
}