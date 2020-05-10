#include <iostream>
#include <vector>
#define mfor(i,s,e) for(auto i = s ; i <= e; ++i)

using namespace std;

int n,xi;
int node[103][103];

inline int sub(int& a, int& b)
{
	return a > b ? a - b : b-a;
}
inline int dist(int& x1, int& x2, int& y1, int& y2)
{
	return sub(x1,x2)+sub(y1,y2);
}

void input()
{
	cin>>n;
	xi = n+2;
	int a,b;
	vector<pair<int,int>>p;
	p.resize(n+3);
	mfor(i, 1, xi) {
		cin>>a>>b;
		p[i].first = a;p[i].second;
	}


}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while (T)
	{
		input();
	}
}