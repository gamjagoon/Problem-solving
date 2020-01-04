#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<string>q;
bool is_nec(const string& a)
{
	string tmp(a+a);
	int len = a.length();
	for (int i = 1; i < len; ++i)
	{
		//printf("%d ",i);
		for (int j = 0; j < len; ++j) {
			if (tmp[i + j] > a[j]) {
				break;
			}
			else if(tmp[i + j] == a[j])continue;
			else {
				//printf("return\n");
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string a;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	string max;
	int len = a.length();
	int sindex = 0;
	while(sindex < len)
	{
		for (int i = len-sindex; i >=1;--i) {
			string tmp= a.substr(sindex,i);
			if(is_nec(tmp))
			{
				sindex = i+sindex;
				q.push(tmp);
				break;
			}
		}
	}
	while (!q.empty())
	{
		string tmp = q.front();
		cout<<'('<<tmp<<')';
		q.pop();
	}
	return 0;
}