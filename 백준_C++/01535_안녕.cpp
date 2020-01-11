#include <iostream>
#include <vector>
#define mfor(i,a,b) for(auto i = a; i <= b; ++i)
using namespace std;
typedef pair<int,int>p;
vector<p>v;
int result = 0;
int N;
inline int mMax(int a,int b){
	return a > b ? a :b;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>N;
	v.resize(N);
	mfor(i, 0, N - 1) {
		cin>>v[i].first;
	}
	mfor(i, 0, N - 1) {
		cin >> v[i].second;
	}
	cout<<result<<'\n';
	return 0;
}