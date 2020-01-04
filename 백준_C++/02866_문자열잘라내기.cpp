#include <iostream>
#include<map>
using namespace std;
string a[1002];
map<string,int>m;
int R,C,cnt = 0;

bool dup(int mid)
{
	for (int j = 0; j < C; ++j)
	{
		string tmp("");
		for (int i = mid; i < R; i++)
			tmp += a[i][j];
		if(m[tmp])return false;
		else m[tmp]++;
	}
	return true;
}
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>R>>C;
	char tmp;
	for (int i = 0; i < R; i++)
		cin >> a[i];
}
void calc()
{
	if(R==2)return ;
	int start = 0,end = R-1,mid = 0;
	bool flag = false;
	while (start <= end)
	{
		mid = (start + end) / 2;
		bool chk = true;
		chk = dup(mid);
		m.clear();
		if (!chk)
			end = mid - 1;
		else
			start = mid + 1;
		flag = chk;
	}
	if(!flag)cnt = mid -1;
	else cnt = mid;
}
int main()
{
	init();
	calc();
	cout<<cnt<<endl;
	return 0;
}