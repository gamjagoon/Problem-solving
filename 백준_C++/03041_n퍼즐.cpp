#include <iostream>
using namespace std;

typedef pair<int,int> p;
p table[16];

inline int sub(int a,int b)
{
	if(a > b)return a-b;
	else return b-a;
}
inline int dist_mehaton(int x1,int y1,int x2,int y2)
{
	return sub(x1,x2) + sub(y1,y2);
}

int solve()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0 ; i < 4; ++i)
	{
		for(int j = 0 ; j < 4; ++j){
			table[i*4+j].first =i;
			table[i*4+j].second =j;
		}
	}
	char tmp;
	int res = 0;
	for(int i = 0 ; i < 4; ++i)
	{
		for(int j = 0 ; j < 4; ++j){
			cin>>tmp;
			if(tmp == '.')continue;
			tmp-='A';
			res+= dist_mehaton(i,j,table[tmp].first,table[tmp].second);
		}
	}
	return res;
}


int main()
{
	cout<<solve();
	return 0;
}